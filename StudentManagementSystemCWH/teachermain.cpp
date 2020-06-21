#include "teachermain.h"
#include "ui_teachermain.h"
#include <QStackedLayout>
#include<QDebug>
#include"addstudent.h"
#include"selectstudent.h"
#include"sortstudent.h"
#include"modifystudent.h"
#include"teacherfunc.h"
TeacherMain::TeacherMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherMain)
{
    ui->setupUi(this);
    //Teacherfunc=new teacherfunc;
    //modifystudent=new Modifystudent;
    //Addstudent=new addstudent;
    //selectstudent=new Selectstudent;
    //sortstudent=new Sortstudent;

    //stackLayout->addWidget(Teacherfunc);
    //stackLayout->addWidget(Addstudent);
    //stackLayout->addWidget(selectstudent);
    //stackLayout->addWidget(modifystudent);
    //stackLayout->addWidget(sortstudent);

    //connect(Teacherfunc,&teacherfunc::display,stackLayout,&QStackedLayout::setCurrentIndex);
    //connect(Addstudent, &addstudent::display,stackLayout,&QStackedLayout::setCurrentIndex);
    //connect(modifystudent, &Modifystudent::display, stackLayout, &QStackedLayout::setCurrentIndex);
    //connect(selectstudent, &Selectstudent::display, stackLayout, &QStackedLayout::setCurrentIndex);
    //connect(sortstudent, &Sortstudent::display, stackLayout, &QStackedLayout::setCurrentIndex);
}

TeacherMain::~TeacherMain()
{
    delete ui;
}

void TeacherMain::on_enterButton_clicked()
{
    this->hide();
    cwhteacherfunc.exec();
}

void TeacherMain::on_relogin_clicked()
{
    QApplication::exit();
}
