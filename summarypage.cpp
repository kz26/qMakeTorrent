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

#include "summarypage.h"
#include "ui_summarypage.h"

#include <QtGui>

SummaryPage::SummaryPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::SummaryPage)
{
    ui->setupUi(this);
}

void SummaryPage::initializePage() {
    ui->summaryTextBox->clear();
    QString inputPath = field("inputPath").toString();
    ui->summaryTextBox->append(QString("<b>Input path:</b> %1\n").arg(inputPath));
    if (QFileInfo(inputPath).isDir())
        ui->summaryTextBox->append("<b>Input type:</b> directory\n");
    else
        ui->summaryTextBox->append("<b>Input type:</b> file\n");
    ui->summaryTextBox->append(QString("<b>Batch mode: %1\n").arg(field("batchMode").toString()));
    ui->summaryTextBox->append(QString("<b>Output path:</b> %1\n").arg(field("outputPath").toString()));

    foreach(const QString &webSeed, field("webSeeds").toString().split('\n')) {
        if (!webSeed.isEmpty())
            ui->summaryTextBox->append(QString("<b>Web seed:</b> %1\n").arg(webSeed));
    }

    foreach(const QString &tracker, field("announceUrls").toString().split('\n')) {
        if (!tracker.isEmpty())
            ui->summaryTextBox->append(QString("<b>Tracker:</b> %1\n").arg(tracker));
    }

    ui->summaryTextBox->append(QString("<b>Comment:</b> <pre>%1</pre>\n").arg(field("comment").toString()));

    int pieceSizeIndex = field("pieceSize").toInt();
    int pieceSize;
    if(pieceSizeIndex == 0) {
        pieceSize = 0;
        ui->summaryTextBox->append(QString("<b>Piece size:</b> Auto\n"));
	}
    else {
        pieceSize = 2 << (pieceSizeIndex + 2);
        ui->summaryTextBox->append(QString("<b>Piece size:</b> %1 KB\n").arg(pieceSize));
	}
    ui->summaryTextBox->append(QString("<b>Include file modification times:</b> %1\n").arg(field("includeFileModTimes").toString()));
    ui->summaryTextBox->append(QString("<b>Private torrent:</b> %1\n").arg(field("privateTorrent").toString()));




}

SummaryPage::~SummaryPage()
{
    delete ui;
}
