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
    connect(ui->addFileButton, SIGNAL(clicked()), this, SLOT(browseFile()));
    connect(ui->addDirectoryButton, SIGNAL(clicked()), this, SLOT(browseDirectory()));
}

void InputPage::browseFile() {
    QFileDialog dialog(this);
    if(dialog.exec())
        ui->inputPath->setText(dialog.selectedFiles().first());
}

void InputPage::browseDirectory() {
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);
    if(dialog.exec())
        ui->inputPath->setText(dialog.selectedFiles().first());
}

InputPage::~InputPage()
{
    delete ui;
}
