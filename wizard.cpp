#include "wizard.h"
#include "ui_wizard.h"
#include "intropage.h"
#include "inputpage.h"
#include "trackerspage.h"

Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);
    this->addPage(new IntroPage);
    this->addPage(new InputPage);
    this->addPage(new TrackersPage);

}

Wizard::~Wizard()
{
    delete ui;
}
