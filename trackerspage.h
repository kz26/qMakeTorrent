#ifndef TRACKERSPAGE_H
#define TRACKERSPAGE_H

#include <QWizardPage>

namespace Ui {
class TrackersPage;
}

class TrackersPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit TrackersPage(QWidget *parent = 0);
    ~TrackersPage();

    bool isComplete() const;

public slots:

private:
    Ui::TrackersPage *ui;
};

#endif // TRACKERSPAGE_H
