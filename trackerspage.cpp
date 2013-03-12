#include "trackerspage.h"
#include "ui_trackerspage.h"

TrackersPage::TrackersPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::TrackersPage)
{
    ui->setupUi(this);

    registerField("announceUrls", ui->announceUrls);
    registerField("webSeeds", ui->webSeeds);

    connect(ui->announceUrls, SIGNAL(textChanged()), this, SIGNAL(completeChanged()));
    connect(ui->webSeeds, SIGNAL(textChanged()), this, SIGNAL(completeChanged()));
}

bool TrackersPage::isComplete() const {
    if(ui->announceUrls->toPlainText().length() != 0 || ui->webSeeds->toPlainText().length() != 0)
        return true;
    return false;
}

TrackersPage::~TrackersPage()
{
    delete ui;
}
