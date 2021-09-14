#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include "QtWidgets"
#include <QMessageBox>
#include <QString>
#include "createacc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/image/medicalBackground.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatioByExpanding);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);

    //QPixmap doctor_bkgnd(":/image/medical team.png");
         //doctor_bkgnd = doctor_bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
         //QPalette doc_palette;
         //doc_palette.setBrush(QPalette::Window, doctor_bkgnd);
         //setPalette(doc_palette);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    int Key=3;
    int size;

    QSqlQuery query;
    query.exec("SELECT Username, LoginPass FROM doctor");
    QString db_username, db_password, loginUser, LoginPass;
    while(query.next())
    {
        db_username = query.value(0).toString();
        db_password = query.value(1).toString();

    }

    loginUser= ui->lineEditUser->text();
    LoginPass = ui->lineEditPassword->text();
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


    if(db_username == loginUser && LoginPass==db_password)
    {
        QMessageBox::information(0,"Login", "Sucessful Login");
    }
    else
    {
        QMessageBox::information(0,"Login", "Unsucessful Login");
    }
}










void MainWindow::on_pushButton_createAcc_clicked()
{
   account = new CreateAcc(this);
   account->show();
}

