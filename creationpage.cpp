//
// qMakeTorrent - Advanced torrent creator with batch capability
// Copyright (C) 2013 whitehat2k9 <whitehat2k9@gmail.com>
//
// This file is part of qMakeTorrent.
//
// qMakeTorrent is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// qMakeTorrent is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with qMakeTorrent.  If not, see <http://www.gnu.org/licenses/>.
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
