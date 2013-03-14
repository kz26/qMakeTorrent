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

#include "inputpage.h"
#include "ui_inputpage.h"
#include "wizard.h"
#include <QtGui>

InputPage::InputPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::InputPage)
{
    ui->setupUi(this);

    registerField("inputPath*", ui->inputPath);
    registerField("batchMode", ui->batchMode);
    connect(ui->addFileButton, SIGNAL(clicked()), this, SLOT(browseInputFile()));
    connect(ui->addDirectoryButton, SIGNAL(clicked()), this, SLOT(browseInputDirectory()));
    connect(ui->inputPath, SIGNAL(textChanged(QString)), this, SIGNAL(completeChanged()));
}

void InputPage::browseInputFile() {
    QFileDialog dialog(this);
    dialog.setOption(QFileDialog::ReadOnly, true);
    if(dialog.exec()) {
        ui->inputPath->setText(dialog.selectedFiles().first());
        ui->batchMode->setCheckState(Qt::Unchecked);
        ui->batchMode->setEnabled(false);
    }
}

void InputPage::browseInputDirectory() {
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);
    dialog.setOption(QFileDialog::ReadOnly, true);
    if(dialog.exec()) {
        ui->inputPath->setText(dialog.selectedFiles().first());
        ui->batchMode->setEnabled(true);
    }
}

bool InputPage::isComplete() const {
    return QFileInfo(ui->inputPath->text()).exists();
}

InputPage::~InputPage()
{
    delete ui;
}
