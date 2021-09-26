#include "dashboard.h"
#include "ui_dashboard.h"
#include <QPixmap>
#include <QDebug>
#include <QtSql>
#include <QDate>
#include <QTime>
#include<QGridLayout>
#include <iostream>
#include <QVariant>
#include "Methods.cpp"
DashBoard::DashBoard(QWidget *parent, QString LoginUser) :
    QDialog(parent),

    ui(new Ui::DashBoard)
{

    ui->setupUi(this);

    QString namePatient;

    QSqlQuery query;


    qint16 coloumn=1;
    qint16 row =1;
    QString AppointmentTime;
    QString AppointmentDate;


    QDate d = QDate::currentDate();
    QString Format = "yyyy-dd-MM";
    QTime t = QTime::currentTime();
    ui->lblDate->setText(d.toString(Format));
    ui->lblTime->setText(t.toString());

    //set dates of the Columns
    QDate days = QDate::currentDate();
    days = days.addDays(0);
    ui->lblSund->setText(days.toString("MM-dd"));
    days = days.addDays(1);
    ui->lblMon->setText(days.toString("MM-dd"));
    days = days.addDays(1);
    ui->lblTues->setText(days.toString("MM-dd"));
    days = days.addDays(1);
    ui->lblWedn->setText(days.toString("MM-dd"));
    days = days.addDays(1);
    ui->lblThrus->setText(days.toString("MM-dd"));
    days = days.addDays(1);
    ui->lblFri->setText(days.toString("MM-dd"));
    days = days.addDays(1);
    ui->lblSatur->setText(days.toString("MM-dd"));




    userName = LoginUser;
    qDebug()<<userName;


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





    QSqlQueryModel model;

    model.setQuery("SELECT * FROM patients");
    for(int i = 0; i < model.rowCount(); i++)
    {
     //get the appointment date and time and store in variable
     AppointmentDate = model.record(i).value("Appointments").toDate().toString("yyyy-MM-dd");
     AppointmentTime = model.record(i).value("Appointments").toTime().toString();
     qDebug()<<AppointmentDate<<AppointmentTime;
     //function call to get the number of dates and time ahead of the current date
     coloumn = AppointDate(d,AppointmentDate);
     row = AppointTime(t,AppointmentTime);
     namePatient = model.record(i).value("FirstName").toString()+" "+ model.record(i).value("LastName").toString();

     //add entry label to the grid
     QLabel *l = new QLabel(namePatient);
     l->setStyleSheet("QLabel{background-color:red}");
     QGridLayout *g = ui->GridMain;
     g->addWidget(l,row,coloumn,Qt::Alignment());
    }
    // insert the element at specfic time and day from database











    //possible soluions
    //
    //2. get the coloumn and row index of that label from database and insert it using function "itemAtPosition"




}

DashBoard::~DashBoard()
{
    delete ui;
}



