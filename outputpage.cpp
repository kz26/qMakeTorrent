#include "outputpage.h"
#include "ui_outputpage.h"

#include <QtGui>

OutputPage::OutputPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::OutputPage)
{
    ui->setupUi(this);

    registerField("outputPath*", ui->outputPath);
    connect(ui->browseOutputButton, SIGNAL(clicked()), this, SLOT(browseOutputLocation()));

}

void OutputPage::initializePage() {
    QFileInfo inputInfo(field("inputPath").toString());
    showSaveDir = inputInfo.isDir() && field("batchMode").toBool();
    if(showSaveDir)
        ui->description->setText("Choose a directory to save the torrent files in.");
    else
        ui->description->setText("Choose a name and save location for the torrent file.");
}

void OutputPage::browseOutputLocation() {
    QFileDialog dialog(this);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if(!showSaveDir) {
        dialog.setDefaultSuffix("torrent");
        dialog.setNameFilter("Torrent file (*.torrent)");
    }
    else {
        dialog.setFileMode(QFileDialog::Directory);
        dialog.setOption(QFileDialog::ShowDirsOnly, true);
    }
    if(dialog.exec())
        ui->outputPath->setText(dialog.selectedFiles().first());
}

OutputPage::~OutputPage()
{
    delete ui;
}
