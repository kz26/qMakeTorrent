#include "createtorrent.h"

#include <boost/version.hpp>
#if BOOST_VERSION >= 104800
#define BOOST_ASIO_DYN_LINK
#endif

#include <libtorrent/version.hpp>
#if LIBTORRENT_VERSION_MINOR < 16
#define BOOST_FILESYSTEM_VERSION 2
#include <boost/filesystem/path.hpp>
#endif

#include <libtorrent/create_torrent.hpp>

#include <QtGui>



CreateTorrent::CreateTorrent(QObject *parent) :
    QThread(parent)
{
}

void CreateTorrent::makeTorrentFiles(QString source, bool isBatch, QString comment, QString creator, int pieceSize, bool isPrivate) {
    this->source = source;
    this->isBatch = isBatch;
    this->comment = comment;
    this->creator = creator;
    this->pieceSize = pieceSize;
    this->isPrivate = isPrivate;
    start();

}

// Courtesy of qBitTorrent
#if LIBTORRENT_VERSION_MINOR >= 16
bool file_filter(std::string const& f)
{
        if (filename(f)[0] == '.') return false;
        return true;
}
#else
bool file_filter(boost::filesystem::path const& filename)
{
  if (filename.leaf()[0] == '.') return false;
  return true;
}
#endif

void CreateTorrent::run() {

    QFileInfo inputInfo(this->source);
    if(inputInfo.isDir()) {
        QDirIterator iit(this->source, QDirIterator::Subdirectories);
        while(iit.hasNext()) {
            QString fn = iit.next();
            if(file_filter(boost::filesystem::path(fn.toUtf8().constData())))
                qDebug() << fn;
        }
    }

    using namespace libtorrent;
    file_storage fs;
    add_files(fs, this->source.toUtf8().constData(), file_filter);
    create_torrent torrent(fs);
    this->pieceCount = torrent.num_pieces();
    torrent.add_tracker("http://example.com");
    QFileInfo pSource(this->source);
    set_piece_hashes(torrent, pSource.dir().path().toStdString());
    bencode(std::ostream_iterator<char>(std::cout), torrent.generate());
}

