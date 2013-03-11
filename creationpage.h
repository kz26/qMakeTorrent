#ifndef CREATIONPAGE_H
#define CREATIONPAGE_H

#include <QWizardPage>

namespace Ui {
class CreationPage;
}

class CreationPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit CreationPage(QWidget *parent = 0);
    ~CreationPage();
    void initializePage();
    
private:
    Ui::CreationPage *ui;
};

#endif // CREATIONPAGE_H
