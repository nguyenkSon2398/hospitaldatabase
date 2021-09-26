#include<iostream>
#include <QDate>
#include <QTime>
#include <QDebug>

int AppointDate(QDate d, QString AppointmentDate)
{
    int coloumn =1;
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
    return coloumn;
}

int AppointTime(QTime t,QString AppointmentTime)
{
    int row = 1;
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
    return row;
}
