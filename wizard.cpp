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

#include "wizard.h"
#include "ui_wizard.h"
#include "intropage.h"
#include "inputpage.h"
#include "outputpage.h"
#include "trackerspage.h"
#include "propertiespage.h"
#include "summarypage.h"
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
    this->addPage(new SummaryPage);
    this->addPage(new CreationPage);
    this->setOption(this->DisabledBackButtonOnLastPage, true);
}

Wizard::~Wizard()
{
    delete ui;
}
