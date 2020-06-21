#include "managerfunc.h"
#include "ui_managerfunc.h"
#include"madds.h"
#include"mdelete.h"
#include"addmodule.h"
#include"deletemodule.h"
managerfunc::managerfunc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerfunc)
{
    ui->setupUi(this);
}

managerfunc::~managerfunc()
{
    delete ui;
}

void managerfunc::on_changePeople_clicked()
{
    Madds madds;
    madds.exec();
}

void managerfunc::on_pushButton_clicked()
{
    mdelete m;
    m.exec();
}

void managerfunc::on_addmodule_clicked()
{
    addmodule a;
    a.exec();
}

void managerfunc::on_changeClass_clicked()
{
    deletemodule d;
    d.exec();
}



void managerfunc::on_pushButton_2_clicked()
{
    this->hide();
}
