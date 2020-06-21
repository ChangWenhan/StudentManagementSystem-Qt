#include "studentfunc.h"
#include "ui_studentfunc.h"
#include "course_select.h"
#include "course_inquire.h"
#include "course_delete.h"

StudentFunc::StudentFunc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentFunc)
{
    ui->setupUi(this);
}

StudentFunc::~StudentFunc()
{
    delete ui;
}

void StudentFunc::on_pushButton_clicked()
{
    course_select c;
    c.exec();
}

void StudentFunc::on_pushButton_2_clicked()
{
    course_inquire i;
    i.exec();
}

void StudentFunc::on_course_delete_clicked()
{
    course_delete d;
    d.exec();
}
