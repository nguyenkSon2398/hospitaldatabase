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
DashBoard::DashBoard(QWidget *parent, QString LoginUser) :
    QDialog(parent),

    ui(new Ui::DashBoard)
{

    ui->setupUi(this);

    QSqlQuery query;


    qint16 coloumn=1;
    qint16 row =1;
    QString AppointmentTime;
    QString AppointmentDate;
    QDateTime Atime;

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



    //how to insert appoinment in grid.
    //row elements is time of day
    // colounm elements is the date
    //insert date and time to database-solved using the addTime function SQL

    // if we extract the time and day from the database-solved
    query.exec("SELECT TIME(Appointments) FROM patients");

    while(query.next())
    {
       AppointmentTime = query.value(0).toString();

    }
    qDebug()<<AppointmentTime;
    query.exec("SELECT CAST(Appointments As date) FROM patients");
    while(query.next())
    {
        AppointmentDate = query.value(0).toString();

    }
    qDebug()<<AppointmentDate;
    qDebug()<<d.addDays(0).toString("yyyy-MM-dd");

    //how do we insert the element at the specfic cell-solved
    //below code works
    //QLabel *l = new QLabel("Test");
    //l->setStyleSheet("QLabel{background-color:red}");
    //QGridLayout *g = ui->GridMain;
    //g->addWidget(l,4,5,Qt::Alignment());

    // insert the element at specfic time and day from database
    if(d.addDays(0).toString("yyyy-MM-dd")==AppointmentDate)
    {
        qDebug()<<true;

    }
    else if(d.addDays(1).toString("yyyy-MM-dd")==AppointmentDate)
    {
        qDebug()<<true;
        coloumn +=1;
    }
    else if(d.addDays(2).toString("yyyy-MM-dd")==AppointmentDate)
    {
        qDebug()<<true;
        coloumn +=2;
    }
    else if(d.addDays(3).toString("yyyy-MM-dd")==AppointmentDate)
    {
        qDebug()<<true;
        coloumn +=3;
    }
    else if(d.addDays(4).toString("yyyy-MM-dd")==AppointmentDate)
    {
        qDebug()<<true;
        coloumn +=4;
    }
    else if(d.addDays(5).toString("yyyy-MM-dd")==AppointmentDate)
    {
        qDebug()<<true;
        coloumn +=5;
    }
    else if(d.addDays(6).toString("yyyy-MM-dd")==AppointmentDate)
    {
        qDebug()<<true;
        coloumn +=6;

    }

    if(AppointmentTime == "08:00:00")
    {
        //do nothing
        row=1;
    }
    else if(AppointmentTime =="09:00:00")
    {
        row +=2;

    }

    else if(AppointmentTime =="10:00:00")
    {
        row +=3;

    }
    else if(AppointmentTime =="11:00:00")
    {
        row +=4;

    }
    else if(AppointmentTime =="12:00:00")
    {
        row +=5;

    }
    else if(AppointmentTime =="13:00:00")
    {
        row +=6;

    }
    else if(AppointmentTime =="14:00:00")
    {
        row +=7;

    }

    else if(AppointmentTime =="15:00:00")
    {
        row +=8;

    }
    else if(AppointmentTime =="16:00:00")
    {
        row +=9;

    }
    else if(AppointmentTime =="17:00:00")
    {
        row +=9;

    }


    QLabel *l = new QLabel("Test");
    l->setStyleSheet("QLabel{background-color:red}");
    QGridLayout *g = ui->GridMain;
    g->addWidget(l,row,coloumn,Qt::Alignment());


    //possible soluions
    //
    //2. get the coloumn and row index of that label from database and insert it using function "itemAtPosition"




}

DashBoard::~DashBoard()
{
    delete ui;
}



