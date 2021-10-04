#include "patientview.h"
#include "ui_patientview.h"

patientview::patientview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patientview)
{
    ui->setupUi(this);
}

patientview::~patientview()
{
    delete ui;
}
