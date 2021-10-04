#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QDialog>

namespace Ui {
class patientview;
}

class patientview : public QDialog
{
    Q_OBJECT

public:
    explicit patientview(QWidget *parent = nullptr);
    ~patientview();

private:
    Ui::patientview *ui;
};

#endif // PATIENTVIEW_H
