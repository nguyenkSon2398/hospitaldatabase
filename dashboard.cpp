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
#include <QDateTime>
#include <QPushButton>
#include <QCoreApplication>
DashBoard::DashBoard(QWidget *parent, QString LoginUser) :
    QDialog(parent),

    ui(new Ui::DashBoard)
{
    ui->setupUi(this);
    ui->FramePatient->setVisible(false);
    ui->FrameAppointment->setVisible(true);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer->start(1000);

    QString FnamePatient;
    QString LnamePatient;

    QSqlQuery query;


    qint16 coloumn=1;
    qint16 row =1;
    QString AppointmentTime;
    QString AppointmentDate;





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
     if(AppointmentDate >= QDate::currentDate().toString())
     {
         AppointmentTime = model.record(i).value("Appointments").toTime().toString();
         qDebug()<<AppointmentDate<<AppointmentTime;
         //function call to get the number of dates and time ahead of the current date
         coloumn = AppointDate(AppointmentDate);
         row = AppointTime(AppointmentTime);
         //namePatient = model.record(i).value("FirstName").toString()+" "+ model.record(i).value("LastName").toString();
         FnamePatient = model.record(i).value("FirstName").toString();
         LnamePatient = model.record(i).value("LastName").toString();
         QPushButton *b = new QPushButton(FnamePatient+" "+LnamePatient);
         b->setStyleSheet("QPushButton{background-color:#F25959}");
         QGridLayout *g = ui->GridMain;
         g->addWidget(b,row,coloumn,Qt::Alignment());
         //connect(b,SIGNAL(clicked()),this,SLOT(getPatientInfo(QString,QString,QString,QString)));
         //review
         connect(b,&QPushButton::released,[=] {getPatientInfo(FnamePatient,LnamePatient,AppointmentDate,AppointmentTime);});
     }




     /*
     //add entry label to the grid
     QLabel *l = new QLabel(FnamePatient +" "+ LnamePatient);
     l->setStyleSheet("QLabel{background-color:#F25959}");
     QGridLayout *g = ui->GridMain;
     g->addWidget(l,row,coloumn,Qt::Alignment());
     */
    }
    // insert the element at specfic time and day from database











    //possible soluions
    //
    //2. get the coloumn and row index of that label from database and insert it using function "itemAtPosition"




}

void DashBoard::updateTime()
{
    QDate d = QDate::currentDate();
    QTime t = QTime::currentTime();
    QString Format = "yyyy-dd-MM";
    ui->lblDate->setText(d.toString(Format));
    QString textTime = t.toString("hh : mm : ss");
    ui->lblTime->setText(textTime);
}

DashBoard::~DashBoard()
{
    delete ui;
}




void DashBoard::on_pushBtnPatients_clicked()
{
    ui->FramePatient->setVisible(true);
    ui->FrameAppointment->setVisible(false);
}

void DashBoard::on_pushBtnAppointment_clicked()
{
    ui->FramePatient->setVisible(false);
    ui->FrameAppointment->setVisible(true);

}

void DashBoard::getPatientInfo(QString Fname, QString Lname, QString Date, QString Time)
{
    QString db_Fname, db_Lname, db_Date, db_Time;
    qDebug()<<Fname<<Lname<<Date<<Time;
    int patientindex = 0;
 //shows the information of the patient and notes with it
   //go through each row of the database
    ui->FrameAppointment->setVisible(false);
    ui->FramePatient->setVisible(true);

    QSqlQueryModel query;
    query.setQuery("SELECT * FROM patients");
    for(int i = 0; i < query.rowCount();i++)
    {
        db_Fname= query.record(i).value("FirstName").toString();
        db_Lname = query.record(i).value("LastName").toString();
        db_Date = query.record(i).value("Appointments").toDate().toString("yyyy-MM-dd");
        db_Time = query.record(i).value("Appointments").toTime().toString();
        qDebug()<<db_Fname<<db_Lname<<db_Date<<db_Time;
        if(Fname == db_Fname && Lname == db_Lname&& Date == db_Date&& Time == db_Time)
        {
            patientindex = i;
            break;
        }

    }
    ui->lineEdit_Patient_fname->setText(query.record(patientindex).value("FirstName").toString());
    ui->lineEdit_Patient_Lname->setText(db_Lname = query.record(patientindex).value("LastName").toString());
    ui->lineEdit_patient_App_date->setText(query.record(patientindex).value("Appointments").toDate().toString("yyyy-MM-dd"));
    ui->lineEdit_patient_App_time->setText(query.record(patientindex).value("Appointments").toTime().toString());
    ui->lineEdit_Patient_country->setText(query.record(patientindex).value("Country").toString());
    ui->lineEdit_patient_city->setText(query.record(patientindex).value("City").toString());
    ui->lineEdit_patient_state->setText(query.record(patientindex).value("State").toString());
    ui->lineEdit_patient_phone->setText(query.record(patientindex).value("PhoneNumber").toString());
    ui->lineEdit_patient_email->setText(query.record(patientindex).value("EmailAddress").toString());
    ui->lineEdit_patient_street1->setText(query.record(patientindex).value("StreetAddress1").toString());
    ui->lineEdit_Patient_street2->setText(query.record(patientindex).value("StreetAddress2").toString());
    ui->textEdit_docNotes->setText(query.record(patientindex).value("Notes").toString());
  //check if fname, lname, date and time matches to the database;
    //save index where it best matches
    //open up patient frame and display all the information of the line edit at that index

}




