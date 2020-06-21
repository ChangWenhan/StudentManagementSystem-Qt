#include "teacherfunc.h"
#include "ui_teacherfunc.h"
#include <QStackedLayout>
#include"addstudent.h"
#include"selectstudent.h"
#include"sortstudent.h"
#include"modifystudent.h"

teacherfunc::teacherfunc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacherfunc)
{
    ui->setupUi(this);

}

teacherfunc::~teacherfunc()
{
    delete ui;
}

void teacherfunc::on_addButton_clicked()
{
    addstudent q;
    q.exec();
}

void teacherfunc::on_modifyButton_clicked()
{
    Selectstudent w;
    w.exec();
}

void teacherfunc::on_modifyButton_2_clicked()
{
    Modifystudent e;
    e.exec();
}

void teacherfunc::on_sortButton_clicked()
{
    Sortstudent r;
    r.exec();
}

void teacherfunc::on_exitButton_clicked()
{
    QApplication::exit();
}
