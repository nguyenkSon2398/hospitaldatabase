#ifndef CREATEACC_H
#define CREATEACC_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class CreateAcc;
}

class CreateAcc : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAcc(QWidget *parent = nullptr);
    ~CreateAcc();

private slots:


    void on_pushButton_login_clicked();

private:
    Ui::CreateAcc *ui;
};

#endif // CREATEACC_H
