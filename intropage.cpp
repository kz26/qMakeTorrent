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

#include "intropage.h"
#include "ui_intropage.h"
#include "version.h"

IntroPage::IntroPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::IntroPage)
{
    ui->setupUi(this);

    ui->programTitle->setText(QString("%1 %2").arg(PROGRAM_NAME, PROGRAM_VERSION));
    ui->programUrl->setText(QString("<a href='%1'>%1</a>").arg(PROGRAM_URL));

}

IntroPage::~IntroPage()
{
    delete ui;
}
