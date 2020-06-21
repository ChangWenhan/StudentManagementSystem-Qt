#include "addmodule.h"
#include "ui_addmodule.h"
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QIODevice>

addmodule::addmodule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addmodule)
{
    ui->setupUi(this);
}

addmodule::~addmodule()
{
    delete ui;
}

void addmodule::on_Cancelbtn_clicked()
{
    this->hide();
}

void addmodule::on_OKbtn_clicked()
{
    QString name=this->ui->classname->text();
    QString id=this->ui->classcode->text();
    QString place=this->ui->classplace->text();
    QString score=this->ui->classscore->text();
    QString time=this->ui->classtime->text();
    QString classnum=this->ui->classclass->text();

    QString cnt=name+" "+id+" "+place+" "+score+" "+time+" "+classnum+"\n";

    if(name.length()<1||id.length()<4)
        {
            QMessageBox::critical(this,"wrong","Wrong Information");
        }
    else
        {

            QMessageBox msgbox;
            msgbox.setText("NAME: "+name+"\n"+"ID: "+id+"\n"+"Place: "+place+"\n"+"score: "+score+"\n"+"Time: "+time);
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

void addmodule::clearUserInterface()
{
    this->ui->classname->clear();
    this->ui->classcode->clear();
    this->ui->classplace->clear();
    this->ui->classplace->clear();
    this->ui->classtime->clear();
    this->ui->classscore->setFocus();
}

void addmodule::writeToFile(QString cnt)
{

    QFile file("module.txt");
    if(! file.open(QIODevice::Append | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    out<<cnt;

}
