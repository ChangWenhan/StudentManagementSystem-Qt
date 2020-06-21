#include "managermenu.h"
#include "ui_managermenu.h"
#include"managerfunc.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
Managermenu::Managermenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Managermenu)
{
    ui->setupUi(this);
}

Managermenu::~Managermenu()
{
    delete ui;
}

void Managermenu::on_pushButton_2_clicked()
{
    this->close();
}

int Managermenu::readFromFile()               //读取文件
{
    QFile file("manager.txt");
    if(! file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        man_lines.append(line);
    }
    file.close();
    return 0;
}

void Managermenu::on_Loginbtn_clicked()
{
    QString line_account="admin",line_password="admin";
    account=this->ui->lineEdit->text();
    password=this->ui->lineEdit_2->text();
    if(readFromFile()==-1)
    {
        QMessageBox::warning(nullptr, "Warning", "Defeat");
        this->close();
    }


    int i=0;                           //遍历查询
    for(i=0;i<man_lines.length();i++)
    {
        QString line=man_lines.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
        if(account==linesplit.at(1)&&password==linesplit.at(5))
        {
           this->hide();
           cwhmanagerfunc.exec();
        }
        else
        {

            //QMessageBox::critical(this,"Wrong","Login Failed,Incorrect account or password.");
        }
    }
}
