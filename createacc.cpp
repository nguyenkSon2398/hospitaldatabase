#include "createacc.h"
#include "ui_createacc.h"
#include "mainwindow.h"
#include <QtSql>
CreateAcc::CreateAcc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAcc)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/image/medicalBackground.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatioByExpanding);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);
}

CreateAcc::~CreateAcc()
{
    delete ui;
}
bool isitEmpty(QString&input)
{
    return input.isEmpty();
}
void CreateAcc::on_pushButton_login_clicked()
{
    int Key=3;
    int size;
    bool input=true;
    QSqlQuery query;
    QString loginUser, LoginPass, FName, LName, Email,phoneNum, Street1, Street2, City ;

    while(input!=false)
    {
        //grabs lineedit of username and store it login user
        loginUser= ui->LineEditUserName->text();
        //returns true if the string is empty, returns false if not empty
        input = isitEmpty(loginUser);
        qDebug()<<loginUser;
        if(input == true)
        {
            QMessageBox::information(0,"Missing","Please fill in the Username box");
        }


    }
    input= true;
    while(input!=false)
    {
        LoginPass = ui->lineEditPassword->text();
        input=isitEmpty(LoginPass);
        qDebug()<<LoginPass;
        if(input == true)
        {
            QMessageBox::information(0,"Missing","Please fill in the Password box");
        }

    }
    input= true;
    while(input!=false)
    {
        FName = ui->lineEditFirstName->text();
        input=isitEmpty(FName);
        if(input == true)
        {
            QMessageBox::information(0,"Missing","Please fill in the First Name box");
        }
    }
    input= true;
    while(input!=false)
    {
        LName = ui->lineEditLastName->text();
        input=isitEmpty(LName);
        if(input == true)
        {
            QMessageBox::information(0,"Missing","Please fill in the Last Name box");
        }
    }
    input= true;
    while(input!=false)
    {
        Email = ui->lineEditEmail->text();
        input=isitEmpty(Email);
        if(input == true)
        {
            QMessageBox::information(0,"Missing","Please fill in the Email box");
        }
    }
    input= true;
    while(input!=false)
    {
        phoneNum = ui->lineEditPhoneNumber->text();
        input=isitEmpty(phoneNum);
        if(input == true)
        {
            QMessageBox::information(0,"Missing","Please fill in the Phone Number box");
        }
    }
    input= true;
    while(input!=false)
    {
        Street1= ui->lineEditStreetAddress1->text();
        input=isitEmpty(Street1);
        if(input == true)
        {
            QMessageBox::information(0,"Missing","Please fill in the Street1 box");
        }
    }

    Street2 = ui->lineEditStreetAddress2->text();
    input= true;
    while(input!=false)
    {
        City= ui->lineEditCity->text();
        input=isitEmpty(City);
        if(input == true)
        {
            QMessageBox::information(0,"Missing","Please fill in the City box");
        }
    }

    size = LoginPass.size();
    for(int k = 0; k < Key; k++)
    {
        //round 1: Hospital
        QChar temp = LoginPass[0];
        for(int i = 0; i < size; i ++)
        {
            if(i!=size-1)
            {
              LoginPass[i]= LoginPass[i+1];
            }

        }
        LoginPass[size-1]=temp;
        qDebug()<<LoginPass;


    }

    query.prepare("Insert INTO doctor(FirstName,LastName,UserName,LoginPass,Email,PhoneNumber,StreetAddress1,StreetAddress2,City)"
                  "VALUES(:Fname,:Lname,:userName,:pass,:email,:phone,:address1,:address2,:city)");

    if(input == false)
    {
        query.bindValue(":Fname",FName);
        query.bindValue(":Lname",LName);
        query.bindValue(":userName",loginUser);
        query.bindValue(":pass",LoginPass);
        query.bindValue(":email",Email);
        query.bindValue(":phone",phoneNum);
        query.bindValue(":address1",Street1);
        query.bindValue(":address2",Street2);
        query.bindValue(":city", City);
        query.exec();
        QMessageBox::information(0,"Sucessful","The account has been sucessfully made!");
        close();
    }
    else
    {
        QMessageBox::information(0,"Unsucessful","The account cannot be made!");
    }


}

