#include "summarypage.h"
#include "ui_summarypage.h"

#include <QtGui>

SummaryPage::SummaryPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::SummaryPage)
{
    ui->setupUi(this);
}

void SummaryPage::initializePage() {
    QString inputPath = field("inputPath").toString();
    ui->summaryTextBox->append(QString("<b>Input path:</b> %1\n").arg(inputPath));
    if (QFileInfo(inputPath).isDir())
        ui->summaryTextBox->append("<b>Input type:</b> directory\n");
    else
        ui->summaryTextBox->append("<b>Input type:</b> file\n");
    ui->summaryTextBox->append(QString("<b>Batch mode: %1\n").arg(field("batchMode").toString()));
    ui->summaryTextBox->append(QString("<b>Output path:</b> %1\n").arg(field("outputPath").toString()));

    foreach(const QString &webSeed, field("webSeeds").toString().split('\n')) {
        if (!webSeed.isEmpty())
            ui->summaryTextBox->append(QString("<b>Web seed:</b> %1\n").arg(webSeed));
    }

    foreach(const QString &tracker, field("announceUrls").toString().split('\n')) {
        if (!tracker.isEmpty())
            ui->summaryTextBox->append(QString("<b>Tracker:</b> %1\n").arg(tracker));
    }

    ui->summaryTextBox->append(QString("<b>Comment:</b> <pre>%1</pre>\n").arg(field("comment").toString()));

    int pieceSizeIndex = field("pieceSize").toInt();
    int pieceSize;
    if(pieceSizeIndex == 0)
        pieceSize = 0;
    else
        pieceSize = 1024 * (2 << (pieceSizeIndex + 2));
    if (pieceSize == 0)
        ui->summaryTextBox->append(QString("<b>Piece size:</b> Auto\n"));
    else
        ui->summaryTextBox->append(QString("<b>Piece size:</b> %1 KB\n").arg(pieceSize));
    ui->summaryTextBox->append(QString("<b>Include file modification times:</b> %1\n").arg(field("includeFileModTimes").toString()));
    ui->summaryTextBox->append(QString("<b>Private torrent:</b> %1\n").arg(field("privateTorrent").toString()));




}

SummaryPage::~SummaryPage()
{
    delete ui;
}
