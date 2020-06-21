#include "madds.h"
#include "ui_madds.h"
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QIODevice>

Madds::Madds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Madds)
{
    ui->setupUi(this);
}

Madds::~Madds()
{
    delete ui;
}

//管理员添加学生及教师信息功能部分代码
void Madds::on_addbtn_clicked()
{
    QString name=this->ui->le_name->text();
    QString id=this->ui->le_ID->text();
    QString passwd=this->ui->le_passwd->text();
    QString age=this->ui->comboBox->currentText();
    QString major=this->ui->comboBox_2->currentText();
    QString sex=this->ui->comboBox_3->currentText();
    QString classnum=this->ui->le_class->text();

    QString content=name+"\n"+id+"\n"+age+"\n"+sex+"\n"+major+"\n"+passwd;

    QString cnt=name+" "+id+" "+sex+" "+age+" "+major+" "+classnum+" "+passwd+"\n";
    QString cnt2=name+" "+id+" "+sex+" "+age+" "+major+" "+passwd+"\n";


    if(name.length()<1 || id.length()<1 ||passwd.length()<6){
        QMessageBox::critical(this,"WRONG","Incomplete necessary information");
    }
    else {
        int ret = QMessageBox::question(this,"Please check the information",content,"Save","Cancel");
        if(ret==0&&classnum.length()!=0)
        {
            clearUserInterface();
            writeToFile(cnt);
        }
        else if(ret==0&&classnum.length()==0)
        {
            clearUserInterface();
            writeToFile_2(cnt);
        }
    }
}

void Madds::writeToFile(QString cnt)
{
    QFile file("message.txt");
    if(! file.open(QIODevice::Append | QIODevice::Text ) )
    {
        QMessageBox::critical(this,"wrong","fail to open the file","OK");
        return;
    }

    QTextStream out(&file);
    out<<cnt;
    file.close();
}

void Madds::writeToFile_2(QString cnt)
{
    QFile file("teacher.txt");
    if(! file.open(QIODevice::Append | QIODevice::Text ) )
    {
        QMessageBox::critical(this,"wrong","fail to open the file","OK");
        return;
    }

    QTextStream out(&file);
    out<<cnt;
    file.close();
}

void Madds::clearUserInterface()
{
    this->ui->le_name->clear();
    this->ui->le_ID->clear();
    this->ui->le_class->clear();
    this->ui->le_passwd->clear();
    this->ui->comboBox->setCurrentIndex(0);
    this->ui->comboBox_2->setCurrentIndex(0);
    this->ui->comboBox_3->setCurrentIndex(0);
}



void Madds::on_backbtn_clicked()
{
    this->hide();
}
