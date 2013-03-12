#ifndef OUTPUTPAGE_H
#define OUTPUTPAGE_H

#include <QtGui>

namespace Ui {
class OutputPage;
}

class OutputPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit OutputPage(QWidget *parent = 0);
    ~OutputPage();
    void initializePage();

public slots:
    void browseOutputLocation();
    
private:
    Ui::OutputPage *ui;
    bool showSaveDir;
};

#endif // OUTPUTPAGE_H
