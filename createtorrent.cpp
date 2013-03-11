#include "createtorrent.h"

#include <boost/version.hpp>
#if BOOST_VERSION >= 104800
#define BOOST_ASIO_DYN_LINK
#endif

#include <libtorrent/version.hpp>
#if LIBTORRENT_VERSION_MINOR < 16
#define BOOST_FILESYSTEM_VERSION 2
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

bool addFileFilter(std::string const& f) {
    return true;
}

void CreateTorrent::run() {
    using namespace libtorrent;
    file_storage fs;
    //qDebug() << this->source;
    add_files(fs, this->source.toUtf8().constData());
    create_torrent torrent(fs);
    this->pieceCount = torrent.num_pieces();
    torrent.add_tracker("http://example.com");
    QFileInfo pSource(this->source);
    set_piece_hashes(torrent, pSource.dir().path().toStdString());
    bencode(std::ostream_iterator<char>(std::cout), torrent.generate());
}


