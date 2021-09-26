#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QTimer>
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
    QTimer *timer;
};

#endif // DASHBOARD_H
