#include "trackerspage.h"
#include "ui_trackerspage.h"

TrackersPage::TrackersPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::TrackersPage)
{
    ui->setupUi(this);

    registerField("announceUrls", ui->announceUrls);
    registerField("webSeeds", ui->webSeeds);

    connect(ui->announceUrls, SIGNAL(textChanged()), this, SLOT(inputChanged()));
    connect(ui->webSeeds, SIGNAL(textChanged()), this, SLOT(inputChanged()));
}

bool TrackersPage::isComplete() const {
    if(ui->announceUrls->toPlainText().length() != 0 || ui->webSeeds->toPlainText().length() != 0)
        return true;
    return false;
}

void TrackersPage::inputChanged() {
    emit(completeChanged());
}

TrackersPage::~TrackersPage()
{
    delete ui;
}
