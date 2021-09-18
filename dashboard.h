#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>

namespace Ui {
class DashBoard;
}

class DashBoard : public QDialog
{
    Q_OBJECT

public:
    explicit DashBoard(QWidget *parent = nullptr,QString LoginUser="");

    ~DashBoard();

private:
    Ui::DashBoard *ui;
    QString userName;
    QString userPass;
};

#endif // DASHBOARD_H
