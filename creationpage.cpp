#include "creationpage.h"
#include "ui_creationpage.h"
#include "createtorrent.h"
#include <QtGui>

CreationPage::CreationPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::CreationPage)
{
    ui->setupUi(this);
}

CreationPage::~CreationPage()
{
    delete ui;
}

void CreationPage::initializePage() {
    CreateTorrent *ctThread = new CreateTorrent(this);
    ctThread->makeTorrentFiles(field("inputPath").toString(), false, field("comment").toString(), field("creator").toString(), field("pieceSize").toInt(), field("privateTorrent").toBool());
}
