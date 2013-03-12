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

void CreationPage::updateProgress(int i) {
    ui->progressBar->setValue(i);
}

void CreationPage::logAddedFile(QString filename) {
    ui->statusLog->appendPlainText(filename);
}

void CreationPage::setFinishedText() {
    ui->titleLabel->setText("Torrent creation completed.");
}

void CreationPage::initializePage() {
    CreateTorrent *ctThread = new CreateTorrent(this);
    connect(ctThread, SIGNAL(updateProgress(int)), this, SLOT(updateProgress(int)));
    connect(ctThread, SIGNAL(logStatusMessage(QString)), this, SLOT(logAddedFile(QString)));
    connect(ctThread, SIGNAL(finished()), this, SLOT(setFinishedText()));
    ctThread->makeTorrentFiles(field("inputPath").toString(), field("batchMode").toBool(), field("announceUrls").toString(), field("webSeeds").toString(), field("comment").toString(), field("creator").toString(), field("pieceSize").toInt(), field("privateTorrent").toBool());
}
