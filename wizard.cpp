#include "wizard.h"
#include "ui_wizard.h"
#include "intropage.h"
#include "inputpage.h"
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
    this->addPage(new TrackersPage);
    this->addPage(new PropertiesPage);
    this->addPage(new CreationPage);
    this->setOption(this->DisabledBackButtonOnLastPage, true);
}

Wizard::~Wizard()
{
    delete ui;
}
