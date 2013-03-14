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
    registerField("creator", ui->creator);
    registerField("pieceSize", ui->pieceSize);
    registerField("privateTorrent", ui->privateTorrent);

    ui->creator->setText(QString("%1 %2").arg(PROGRAM_NAME, PROGRAM_VERSION));
}

void PropertiesPage::initializePage() {
    ui->pieceSize->addItem("Auto", 0);
    for (int x = 16; x <= 4096; x <<= 1) {
        QString label = QString("%1 KB").arg(QString::number(x));
        ui->pieceSize->addItem(label, x * 1024);
    }
}

PropertiesPage::~PropertiesPage()
{
    delete ui;
}
