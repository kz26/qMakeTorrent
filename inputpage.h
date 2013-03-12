#ifndef INPUTPAGE_H
#define INPUTPAGE_H

#include <QWizardPage>

namespace Ui {
class InputPage;
}

class InputPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit InputPage(QWidget *parent = 0);
    ~InputPage();
    bool isComplete() const;
    
public slots:
    void browseInputFile();
    void browseInputDirectory();

private:
    Ui::InputPage *ui;
};

#endif // INPUTPAGE_H
