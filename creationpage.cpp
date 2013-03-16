//
// Copyright (c) 2013 whitehat2k9 <whitehat2k9@gmail.com>
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
#include <QtGui>

CreationPage::CreationPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::CreationPage)
{
    ui->setupUi(this);
}

CreationPage::~CreationPage()
{
    delete ui;
}

void CreationPage::updateProgress(int i) {
    ui->progressBar->setValue(i);
}

void CreationPage::logAddedFile(QString filename) {
    ui->statusLog->appendPlainText(filename);
}

void CreationPage::setFinishedText() {
    ui->titleLabel->setText("Torrent creation completed.");
}

void CreationPage::initializePage() {
    CreateTorrent *ctThread = new CreateTorrent(this);
    connect(ctThread, SIGNAL(updateProgress(int)), this, SLOT(updateProgress(int)));
    connect(ctThread, SIGNAL(logStatusMessage(QString)), this, SLOT(logAddedFile(QString)));
    connect(ctThread, SIGNAL(finished()), this, SLOT(setFinishedText()));
    ctThread->makeTorrentFiles(field("inputPath").toString(), field("outputPath").toString(), field("batchMode").toBool(), field("announceUrls").toString(), field("webSeeds").toString(), field("comment").toString(), field("creator").toString(), field("pieceSize").toInt(), field("privateTorrent").toBool());
}
