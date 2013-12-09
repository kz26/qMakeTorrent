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

#include "creationpage.h"
#include "ui_creationpage.h"
#include "createtorrent.h"
#include "version.h"
#include <libtorrent/create_torrent.hpp>
#include <QtGui>

CreationPage::CreationPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::CreationPage)
{
    ui->setupUi(this);
    torrentDone = false;
}

CreationPage::~CreationPage()
{
    delete ui;
}

bool CreationPage::isComplete() const {
    return torrentDone;
}

void CreationPage::updateProgress(int i) {
    ui->progressBar->setValue(i);
}

void CreationPage::logAddedFile(QString filename) {
    ui->statusLog->appendPlainText(filename);
}

void CreationPage::triggerFinished() {
    ui->titleLabel->setText("Torrent creation completed.");
    torrentDone = true;
    emit completeChanged();
}

void CreationPage::initializePage() {
    CreateTorrent *ctThread = new CreateTorrent(this);
    connect(ctThread, SIGNAL(updateProgress(int)), this, SLOT(updateProgress(int)));
    connect(ctThread, SIGNAL(logStatusMessage(QString)), this, SLOT(logAddedFile(QString)));
    connect(ctThread, SIGNAL(finished()), this, SLOT(triggerFinished()));

    using namespace libtorrent;

    int includeFileModTimes = field("includeFileModTimes").toBool() ? create_torrent::modification_time : 0;
    int includeSymlinks = field("includeSymlinks").toBool() ? create_torrent::symlinks : 0;
    int flags = includeFileModTimes | includeSymlinks;

    int pieceSizeIndex = field("pieceSize").toInt();
    int pieceSize;
    if(pieceSizeIndex == 0)
        pieceSize = 0;
    else
        pieceSize = 1024 * (2 << (pieceSizeIndex + 2));

    ctThread->makeTorrentFiles(field("inputPath").toString(), field("outputPath").toString(), field("batchMode").toBool(), field("announceUrls").toString(), field("webSeeds").toString(), field("comment").toString(), QString("%1 %2").arg(PROGRAM_NAME, PROGRAM_VERSION), pieceSize, flags, field("privateTorrent").toBool());
}
