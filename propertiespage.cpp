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

#include "propertiespage.h"
#include "ui_propertiespage.h"
#include "version.h"
#include <QtGui>

PropertiesPage::PropertiesPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::PropertiesPage)
{
    ui->setupUi(this);

    registerField("comment", ui->comment);
    registerField("pieceSize", ui->pieceSize);
    registerField("includeFileModTimes", ui->includeFileModTimes);
    registerField("includeSymlinks", ui->includeSymlinks);
    registerField("privateTorrent", ui->privateTorrent);

}

void PropertiesPage::initializePage() {
    ui->pieceSize->addItem("Auto", 0);
    for (int x = 16; x <= 4096; x <<= 1) {
        QString label = QString("%1 KB").arg(QString::number(x));
        ui->pieceSize->addItem(label, x * 1024);
    }
    ui->pieceSize->setCurrentIndex(0);
}

PropertiesPage::~PropertiesPage()
{
    delete ui;
}
