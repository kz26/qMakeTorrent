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

#include "wizard.h"
#include "ui_wizard.h"
#include "intropage.h"
#include "inputpage.h"
#include "outputpage.h"
#include "trackerspage.h"
#include "propertiespage.h"
#include "creationpage.h"
#include "version.h"

Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);

    this->setWindowTitle(QString("%1 %2").arg(PROGRAM_NAME, PROGRAM_VERSION));

    this->addPage(new IntroPage);
    this->addPage(new InputPage);
    this->addPage(new OutputPage);
    this->addPage(new TrackersPage);
    this->addPage(new PropertiesPage);
    this->addPage(new CreationPage);
    this->setOption(this->DisabledBackButtonOnLastPage, true);
}

Wizard::~Wizard()
{
    delete ui;
}
