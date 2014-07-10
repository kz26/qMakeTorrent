/* * Copyright (c) 2013 kz26
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CREATETORRENT_H
#define CREATETORRENT_H

#include <boost/version.hpp>
#if BOOST_VERSION >= 104800
#define BOOST_ASIO_DYN_LINK
#endif

#include <libtorrent/version.hpp>
#if LIBTORRENT_VERSION_MINOR < 16 && LIBTORRENT_VERSION_MAJOR < 1
#define BOOST_FILESYSTEM_VERSION 2
#endif

#include <QThread>
#include <QStringList>

class CreateTorrent : public QThread
{
    Q_OBJECT
public:
    explicit CreateTorrent(QObject *parent = 0);
    void makeTorrentFiles(QString source, QString outputLocation, bool isBatch, QString announceUrls, QString webSeeds, QString comment, QString creator, int pieceSizeIndex, int flags, bool isPrivate);
    void sendProgressSignal(int i);
signals:
    void updateProgress(int i);
    void logStatusMessage(QString msg);

public slots:
    
private:
    void run();
    QString source;
    QString outputLocation;
    bool isBatch;
    QStringList announceUrls;
    QStringList webSeeds;
    QString comment;
    QString creator;
    int pieceSize;
    int flags;
    bool isPrivate;
    int pieceCount;

};

#endif // CREATETORRENT_H
