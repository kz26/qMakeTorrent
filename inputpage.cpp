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
