#include "propertiespage.h"
#include "ui_propertiespage.h"
#include "version.h"
#include <QtGui>

PropertiesPage::PropertiesPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::PropertiesPage)
{
    ui->setupUi(this);

    registerField("comment", ui->comment);
    registerField("creator", ui->creator);
    registerField("pieceSize", ui->pieceSize);
    registerField("privateTorrent", ui->privateTorrent);

    ui->creator->setText(QString("%1 %2").arg(PROGRAM_NAME, PROGRAM_VERSION));
}

void PropertiesPage::initializePage() {
    ui->pieceSize->addItem("Auto", 0);
    for (int x = 16; x <= 4096; x <<= 1) {
        QString label = QString("%1 KB").arg(QString::number(x));
        ui->pieceSize->addItem(label, x * 1024);
    }
}

PropertiesPage::~PropertiesPage()
{
    delete ui;
}
