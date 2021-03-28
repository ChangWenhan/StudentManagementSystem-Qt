#include "system.h"
#include "ui_system.h"
#include "addstu.h"
#include "addtea.h"
#include "addcourse.h"
#include "sysdel.h"
#include "mainwindow.h"
system::system(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::system)
{
    ui->setupUi(this);
}

system::~system()
{
    delete ui;
}

void system::on_btn_addstu_clicked()
{
    addstu a;
    a.exec();
}

void system::on_btn_addtea_clicked()
{
    addtea a;
    a.exec();
}

void system::on_btn_addcourse_clicked()
{
    addcourse a;
    a.exec();
}

void system::on_btn_del_clicked()
{
    sysdel a;
    a.exec();
}

void system::on_btn_cancel_clicked()
{
    this->close();
}

void system::on_btn_return_clicked()
{
    this->close();
    MainWindow *main_window=new MainWindow;
    main_window->show();
}
