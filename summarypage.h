#ifndef SUMMARYPAGE_H
#define SUMMARYPAGE_H

#include <QWizardPage>

namespace Ui {
class SummaryPage;
}

class SummaryPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit SummaryPage(QWidget *parent = 0);
    ~SummaryPage();

    void initializePage();
    
private:
    Ui::SummaryPage *ui;
};

#endif // SUMMARYPAGE_H
