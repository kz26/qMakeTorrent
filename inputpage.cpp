#include "inputpage.h"
#include "ui_inputpage.h"
#include "wizard.h"
#include <QtGui>

InputPage::InputPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::InputPage)
{
    ui->setupUi(this);

    registerField("inputPath*", ui->inputPath);
    registerField("outputPath*", ui->outputPath);
    registerField("batchMode", ui->batchMode);
    connect(ui->addFileButton, SIGNAL(clicked()), this, SLOT(browseInputFile()));
    connect(ui->addDirectoryButton, SIGNAL(clicked()), this, SLOT(browseInputDirectory()));
    connect(ui->outputPathButton, SIGNAL(clicked()), this, SLOT(browseOutputDirectory()));
    connect(ui->inputPath, SIGNAL(textChanged(QString)), this, SIGNAL(completeChanged()));
}

void InputPage::browseInputFile() {
    QFileDialog dialog(this);
    dialog.setOption(QFileDialog::ReadOnly, true);
    if(dialog.exec()) {
        ui->inputPath->setText(dialog.selectedFiles().first());
        ui->batchMode->setCheckState(Qt::Unchecked);
        ui->batchMode->setEnabled(false);
    }
}

void InputPage::browseInputDirectory() {
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);
    dialog.setOption(QFileDialog::ReadOnly, true);
    if(dialog.exec()) {
        ui->inputPath->setText(dialog.selectedFiles().first());
        ui->batchMode->setEnabled(true);
    }
}

void InputPage::browseOutputDirectory() {
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);
    if(dialog.exec())
        ui->outputPath->setText(dialog.selectedFiles().first());
}

bool InputPage::isComplete() const {
    return QFileInfo(ui->inputPath->text()).exists() && QFileInfo(ui->outputPath->text()).exists();
}

InputPage::~InputPage()
{
    delete ui;
}
