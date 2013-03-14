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

#include "outputpage.h"
#include "ui_outputpage.h"

#include <QtGui>

OutputPage::OutputPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::OutputPage)
{
    ui->setupUi(this);

    registerField("outputPath*", ui->outputPath);
    connect(ui->browseOutputButton, SIGNAL(clicked()), this, SLOT(browseOutputLocation()));

}

void OutputPage::initializePage() {
    QFileInfo inputInfo(field("inputPath").toString());
    showSaveDir = inputInfo.isDir() && field("batchMode").toBool();
    if(showSaveDir)
        ui->description->setText("Choose a directory to save the torrent files in.");
    else
        ui->description->setText("Choose a name and save location for the torrent file.");
}

void OutputPage::browseOutputLocation() {
    QFileDialog dialog(this);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if(!showSaveDir) {
        dialog.setDefaultSuffix("torrent");
        dialog.setNameFilter("Torrent file (*.torrent)");
    }
    else {
        dialog.setFileMode(QFileDialog::Directory);
        dialog.setOption(QFileDialog::ShowDirsOnly, true);
    }
    if(dialog.exec())
        ui->outputPath->setText(dialog.selectedFiles().first());
}

OutputPage::~OutputPage()
{
    delete ui;
}
