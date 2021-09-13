#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("logindb");
    if(db.open())
    {
        QMessageBox::information(0,"Connection","Database Connected");
    }
    else
    {
        QMessageBox::information(0,"Not Connected", "Database not connected");
    }
    return a.exec();

}
