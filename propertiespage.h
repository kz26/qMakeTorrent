#ifndef PROPERTIESPAGE_H
#define PROPERTIESPAGE_H

#include <QWizardPage>

namespace Ui {
class PropertiesPage;
}

class PropertiesPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit PropertiesPage(QWidget *parent = 0);
    void initializePage();
    ~PropertiesPage();
    
private:
    Ui::PropertiesPage *ui;
};

#endif // PROPERTIESPAGE_H
