#include "teachermenu.h"
#include "ui_teachermenu.h"
#include "teacherfunc.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFile>

Teachermenu::Teachermenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teachermenu)
{
    ui->setupUi(this);
    if(readFromFile()==-1)             //判断读取学生文件是否成功！
    {
        QMessageBox::critical(this,"Wrong","Fail to open file");
        this->close();
    }
}

Teachermenu::~Teachermenu()
{
    delete ui;
}

void Teachermenu::on_pushButton_2_clicked()
{
    this->close();
}

int Teachermenu::readFromFile()               //读取文件
{
    QFile file("teacher.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        tea_lines.append(line);
    }
    file.close();
    return 0;
}


void Teachermenu::on_Loginbtn_clicked()
{
    //QString line_account="admin",line_password="admin";

    int a=0;
    for(a=0;a<tea_lines.length();a++)
    {
        qDebug()<<tea_lines.at(a);
    }


    QString account=this->ui->line_account->text();
    QString password=this->ui->line_password->text();
    if(readFromFile()==-1)
    {
        QMessageBox::warning(nullptr, "Warning", "Defeat");
        this->close();
    }

    int i=0;                           //遍历查询
    for(i=0;i<tea_lines.length();i++)
    {
        QString line=tea_lines.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
        if(account==linesplit.at(1) && password==linesplit.at(5))
        {
           this->hide();
           tfunc.exec();
        }

    }
}
