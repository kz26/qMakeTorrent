#include "wizard.h"
#include "ui_wizard.h"
#include "intropage.h"
#include "inputpage.h"
#include "trackerspage.h"
#include "propertiespage.h"
#include "creationpage.h"

Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);
    this->addPage(new IntroPage);
    this->addPage(new InputPage);
    this->addPage(new TrackersPage);
    this->addPage(new PropertiesPage);
    this->addPage(new CreationPage);
}

Wizard::~Wizard()
{
    delete ui;
}
