#include "menu.h"
#include "ui_menu.h"
#include "studentfunc.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    if(readFromFile()==-1)             //判断读取学生文件是否成功！
    {
        QMessageBox::critical(this,"Wrong","Fail to open file");
        this->close();
    }
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_2_clicked()   //退出功能
{
    this->close();

}

int Menu::readFromFile()               //读取文件
{
    QFile file("message.txt");
    if(! file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        stu_lines.append(line);
    }
    file.close();
    return 0;
}

void Menu::on_Loginbtn_clicked()       //登录功能
{
    QString line_account="admin",line_password="admin";
    account=this->ui->line_account->text();
    password=this->ui->line_password->text();

    int i=0;                           //遍历查询
    for(i=0;i<stu_lines.length();i++)
    {
        QString line=stu_lines.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
        if(account==linesplit.at(1)&&password==linesplit.at(6))
        {
           this->hide();
           cwhstudentfunc.exec();
        }
        else
        {
            qDebug()<<"账号或密码错误";
            //QMessageBox::critical(this,"Wrong","Login Failed,Incorrect account or password.");
        }
    }
}

