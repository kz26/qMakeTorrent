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

#include "trackerspage.h"
#include "ui_trackerspage.h"

TrackersPage::TrackersPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::TrackersPage)
{
    ui->setupUi(this);

    registerField("announceUrls", ui->announceUrls);
    registerField("webSeeds", ui->webSeeds);

    connect(ui->announceUrls, SIGNAL(textChanged()), this, SIGNAL(completeChanged()));
    connect(ui->webSeeds, SIGNAL(textChanged()), this, SIGNAL(completeChanged()));
}

bool TrackersPage::isComplete() const {
    if(ui->announceUrls->toPlainText().length() != 0 || ui->webSeeds->toPlainText().length() != 0)
        return true;
    return false;
}

TrackersPage::~TrackersPage()
{
    delete ui;
}
