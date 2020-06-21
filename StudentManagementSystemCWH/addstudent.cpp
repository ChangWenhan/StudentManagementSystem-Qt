#include "addstudent.h"
#include "ui_addstudent.h"
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QIODevice>

addstudent::addstudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstudent)
{
    ui->setupUi(this);
}

addstudent::~addstudent()
{
    delete ui;
}

void addstudent::on_addButton_clicked()
{
    QString name=this->ui->le_name->text();
    QString id=this->ui->le_id->text();
    QString classnum=this->ui->lineEdit->text();
    QString math=this->ui->mathscore->text();
    QString english=this->ui->englishscore->text();
    QString cpp=this->ui->cppscore->text();

    QString cnt=id+" "+classnum+" "+name+" "+math+" "+english+" "+cpp+"\n";

    if(name.length()<1||id.length()<11)
        {
            QMessageBox::critical(this,"wrong","Wrong Information");
        }
    else
        {

            QMessageBox msgbox;
            msgbox.setText("NAME: "+name+"\n"+"ID: "+id+"\n"+"MATH: "+math+"\n"+"ENGLIAH: "+english+"\n"+"C++: "+cpp);
            msgbox.addButton("确定",QMessageBox::AcceptRole);
            QPushButton*cbtn=msgbox.addButton("取消",QMessageBox::RejectRole);
            msgbox.setDefaultButton(cbtn);
            int ret=msgbox.exec();
            qDebug()<<ret;
            if(ret==0)
                {
                    clearUserInterface();
                    writeToFile(cnt);
                }

        }

}

void addstudent::clearUserInterface()
{
    this->ui->le_name->clear();
    this->ui->le_id->clear();
    this->ui->lineEdit->clear();
    this->ui->mathscore->clear();
    this->ui->englishscore->clear();
    this->ui->cppscore->clear();
    this->ui->le_name->setFocus();
}

void addstudent::writeToFile(QString cnt)
{

    QFile file("score.txt");
    if(! file.open(QIODevice::Append | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    out<<cnt;

}


void addstudent::on_returnbutton_clicked()
{
    this->hide();
}
