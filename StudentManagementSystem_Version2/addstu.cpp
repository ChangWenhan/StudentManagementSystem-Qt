#include "addstu.h"
#include "ui_addstu.h"
#include "QString"
#include "QDebug"
#include "QMessageBox"
#include "QFile"

addstu::addstu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstu)
{
    ui->setupUi(this);
}

addstu::~addstu()
{
    delete ui;
}

void addstu::on_btn_sys_addstu_clicked()
{
    QString name=this->ui->le_stu_name->text();
    QString id=this->ui->le_stu_id->text();
    QString password=this->ui->le_stu_password->text();
    QString college=this->ui->cbb_stu->currentText();
    QString classnum=this->ui->le_stu_class->text();
    QString age=this->ui->le_stu_age->text();
    QString messagebox_out="姓名："+name+"\n"+"学号："+id+"\n"+"密码："+password+"\n"+
                           "院系："+college+"\n"+"班级："+classnum+"\n"+"年龄："+age;
    QString info=name+" "+id+" "+password+" "+college+" "+classnum+" "+age;

    bool charge=name.length()<1||id.length()<9||password.length()<6||
                classnum.length()<6||id.at(0)!="s";

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

void addstu::writeIn(QString info)
{
    this->ui->le_stu_name->clear();
    this->ui->le_stu_id->clear();
    this->ui->le_stu_password->clear();
    this->ui->le_stu_class->clear();
    this->ui->le_stu_age->clear();
    this->ui->le_stu_name->setFocus();

    QFile mFile("student.txt");
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

void addstu::on_btn_sys_addstu_cancel_clicked()
{
    this->close();
}
