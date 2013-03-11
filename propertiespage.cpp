#include "propertiespage.h"
#include "ui_propertiespage.h"
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
}

void PropertiesPage::initializePage() {
    ui->pieceSize->addItem("Auto", 0);
    for (int x = 16; x <= 4096; x *= 2) {
        QString label = QString("%1 KB").arg(QString::number(x));
        ui->pieceSize->addItem(label, x * 1024);
    }
}

PropertiesPage::~PropertiesPage()
{
    delete ui;
}
