#include "addcourse.h"
#include "ui_addcourse.h"
#include "QString"
#include "QDebug"
#include "QMessageBox"
#include "QFile"

addcourse::addcourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcourse)
{
    ui->setupUi(this);
}

addcourse::~addcourse()
{
    delete ui;
}

void addcourse::on_btn_sys_addcou_clicked()
{
    QString name=this->ui->le_course_name->text();
    QString id=this->ui->le_course_id->text();
    QString nature=this->ui->cbb_nature->currentText();
    QString point=this->ui->cbb_point->currentText();
    QString college=this->ui->cbb_college->currentText();
    QString place=this->ui->le_course_place->text();
    QString messagebox_out="课程名称："+name+"\n"+"课程编号："+id+"\n"+"课程性质："+nature+"\n"+"课程学分："+point+"\n"
                           +"开课学院："+college+"\n"+"上课地点："+place;
    QString info=name+" "+id+" "+nature+" "+point+" "+college+" "+place;

    bool charge=name.length()<1||id.length()<1||place.length()<1;

    if(charge==1)
    {
        QMessageBox::critical(this,"错误","信息填写不完整，请检查","确定");
    }
    else
    {
       int ret=QMessageBox::question(this,"请确认",messagebox_out,"确认","取消");
       if(ret==0)
          {
             writeIn(info);
          }
    }
}

void addcourse::writeIn(QString info)
{
    this->ui->le_course_name->clear();
    this->ui->le_course_id->clear();
    this->ui->le_course_place->clear();
    this->ui->le_course_name->setFocus();

    QFile mFile("course.txt");
    if(!mFile.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有写入","确认");
        return;
    }
    QTextStream out(&mFile);
    out<<info<<"\n";
    mFile.flush();
    mFile.close();
}

void addcourse::on_btn_sys_addcoucancel_clicked()
{
    this->close();
}
