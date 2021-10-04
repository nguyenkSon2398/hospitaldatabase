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
public slots:
    void updateTime();
    void getPatientInfo(QString Fname, QString Lname, QString Date, QString Time);





private slots:
    void on_pushBtnPatients_clicked();
    void on_pushBtnAppointment_clicked();

private:
    Ui::DashBoard *ui;
    QString userName;
    QString userPass;
    QTimer *timer;
};

#endif // DASHBOARD_H
