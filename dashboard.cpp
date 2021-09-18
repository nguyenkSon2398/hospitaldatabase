#include "dashboard.h"
#include "ui_dashboard.h"
#include <QPixmap>
#include <QDebug>
#include <QtSql>
DashBoard::DashBoard(QWidget *parent, QString LoginUser) :
    QDialog(parent),
    ui(new Ui::DashBoard)
{
    ui->setupUi(this);
    userName = LoginUser;

    qDebug()<<userName;
    qDebug()<<userPass;
    QSqlQuery query;
    QString Fname;
    QString Lname;
    //syntax for selecting first name and last name using variable
    query.exec("SELECT FirstName, LastName FROM doctor WHERE Username ='"+userName+"'");
    while(query.next())
    {
        Fname = query.value(0).toString();
        Lname =query.value(1).toString();

    }

    QString doctor_name = "Welcome "+ Fname +" "+Lname;
    ui->lblWelcome->setText(doctor_name);

    QPixmap bkgnd(":/image/medicalBackground.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatioByExpanding);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);
}

DashBoard::~DashBoard()
{
    delete ui;
}


