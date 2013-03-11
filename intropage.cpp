#include "intropage.h"
#include "ui_intropage.h"
#include "version.h"

IntroPage::IntroPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::IntroPage)
{
    ui->setupUi(this);

    ui->programTitle->setText(QString("%1 %2").arg(PROGRAM_NAME, PROGRAM_VERSION));
}

IntroPage::~IntroPage()
{
    delete ui;
}
