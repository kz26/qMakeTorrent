#include "trackerspage.h"
#include "ui_trackerspage.h"

TrackersPage::TrackersPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::TrackersPage)
{
    ui->setupUi(this);
}

bool TrackersPage::isComplete() const {
    if(ui->announceUrls->toPlainText().length() || ui->webSeeds->toPlainText().length())
        return true;
    return false;
}

TrackersPage::~TrackersPage()
{
    delete ui;
}
