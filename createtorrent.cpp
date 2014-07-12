//
// Copyright (c) 2013 kz26
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation and/or
// other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
// ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#include "createtorrent.h"

#include <fstream>
#include <boost/filesystem/path.hpp>
#include <boost/bind.hpp>

#include <libtorrent/create_torrent.hpp>

#include <QtGui>

CreateTorrent::CreateTorrent(QObject *parent) :
    QThread(parent)
{
}

void CreateTorrent::makeTorrentFiles(QString source, QString outputLocation, bool isBatch, QString announceUrls, QString webSeeds, QString comment, QString creator, int pieceSize, int flags, bool isPrivate) {
    this->source = source;
    this->outputLocation = outputLocation;
    this->isBatch = isBatch;
    this->announceUrls = announceUrls.split("\n");
    this->webSeeds = webSeeds.split("\n");
    this->comment = comment;
    this->creator = creator;
    this->pieceSize = pieceSize;
    this->flags = flags;
    this->isPrivate = isPrivate;
    start();

}

// Courtesy of qBitTorrent
#if LIBTORRENT_VERSION_MINOR >= 16 || LIBTORRENT_VERSION_MAJOR >= 1
bool file_filter(std::string const& f)
{
        if (libtorrent::filename(f)[0] == '.') return false;
        return true;
}
#else
bool file_filter(boost::filesystem::path const& filename)
{
  if (filename.leaf()[0] == '.') return false;
  return true;
}
#endif

void doProgressUpdate(int i, int total, CreateTorrent *parent) {
    parent->sendProgressSignal((int) (i * 100 / (float) total));
}

void CreateTorrent::sendProgressSignal(int i) {
    emit(updateProgress(i));
}

void CreateTorrent::run() {

    using namespace libtorrent;

    QStringList inputList;
    if(!this->isBatch)
        inputList.append(this->source);
    else {
        QDirIterator iit(this->source);
        while(iit.hasNext()) {
            QString fn = iit.next();
			if(file_filter(fn.toUtf8().constData()))
				inputList.append(fn);
        }
    }

    QStringListIterator inputListIterator(inputList);
    while(inputListIterator.hasNext()) {
        QString input = inputListIterator.next();
        QFileInfo inputInfo(input);
        if(inputInfo.isDir()) {
            QDirIterator iit(input, QDirIterator::Subdirectories);
            while(iit.hasNext()) {
                QString fn = iit.next();
                if(file_filter(fn.toUtf8().constData()))
                    emit(logStatusMessage(QString("[READ] %1").arg(fn)));
            }
        }
		else
			emit(logStatusMessage(QString("[READ] %1").arg(input)));

        QString outputFilename;
        if(!this->isBatch)
            outputFilename = this->outputLocation;
        else
            outputFilename = QDir(this->outputLocation).absoluteFilePath(QDir(input).dirName() + ".torrent");
        QFileInfo outputDir = QFileInfo(outputFilename).dir().absolutePath();
        if (!outputDir.isWritable()) {
            emit(logStatusMessage(QString("[ERROR] %1 is not writeable - aborting").arg(outputFilename)));
            return;
        }

        file_storage fs;
        add_files(fs, input.toUtf8().constData(), file_filter);
        create_torrent torrent(fs, this->pieceSize, -1, this->flags);
        this->pieceCount = torrent.num_pieces();

        foreach(const QString &webSeed, this->webSeeds) {
            if (!webSeeds.isEmpty())
                torrent.add_url_seed(webSeed.trimmed().toStdString());
        }

        int tier = 0;
        foreach(const QString &tracker, this->announceUrls) {
            if (!tracker.isEmpty()) {
                torrent.add_tracker(tracker.trimmed().toStdString(), tier);
                tier++;
            }
        }

        torrent.set_priv(this->isPrivate);
        torrent.set_comment(this->comment.toUtf8().constData());
        torrent.set_creator(this->creator.toUtf8().constData());
        QFileInfo pSource(input);
        set_piece_hashes(torrent, pSource.dir().path().toUtf8().constData(), boost::bind<void>(&doProgressUpdate, _1, torrent.num_pieces(), this));
        std::ofstream outputFile(outputFilename.toUtf8().constData(), std::ios_base::binary | std::ios_base::out);
        bencode(std::ostream_iterator<char>(outputFile), torrent.generate());
        outputFile.close();
        emit(updateProgress(100));
        emit(logStatusMessage(QString("[WRITE] %1").arg(outputFilename)));
    }

}
