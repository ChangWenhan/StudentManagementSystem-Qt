#include "modifystudent.h"
#include "ui_modifystudent.h"
#include<QMessageBox>
#include <QDialog>
#include<QString>
#include<QList>
#include<QTextStream>
#include<QDebug>
#include<QFile>

Modifystudent::Modifystudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifystudent)
{
    ui->setupUi(this);
    if(readfile()==-1)
       {
           this->close();
           QMessageBox::critical(this,"错误","文件读取失败!","确认");
       }
}

Modifystudent::~Modifystudent()
{
    delete ui;
}

int Modifystudent::readfile()
{
    score_line.clear();
    QFile file("score.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
       QString line=in.readLine();
       score_line.append(line);
    }
    file.close();

    int i=0;
    for(i=0;i<score_line.length();i++)
    {
        qDebug()<<score_line.at(i);
    }

    return 0;
}

void Modifystudent::writeIn(QString information)
{
    this->ui->le_addscore_name->clear();
    this->ui->le_addscore_id->clear();
    this->ui->le_addscore_math->clear();
    this->ui->le_addscore_eng->clear();
    this->ui->le_addscore_phy->clear();
    this->ui->le_addscore_name->setFocus();
    QFile mFile("score.txt");
    if(!mFile.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"Wrong","Can't open the file","ok");
        return;
    }
    QTextStream out(&mFile);
    out<<information<<"\n";
    mFile.flush();
    mFile.close();
}


void Modifystudent::on_btn_changedata_change_clicked()
{
    QString name=this->ui->le_addscore_name->text();
    QString id=this->ui->le_addscore_id->text();
    QString math=this->ui->le_addscore_math->text();
    QString eng=this->ui->le_addscore_eng->text();
    QString phy=this->ui->le_addscore_phy->text();
    QString classnum=this->ui->le_class->text();

    int temp=math.toInt()+eng.toInt()+phy.toInt();
    QString sum=QString::number(temp);

    QString messagebox_out="NAME:"+name+"\n"+"ID:"+id+"\n"+"MATH:"+math+"\n"+"ENGLISH:"+eng+"\n"+"C++:"+phy+"\n"+"sum:"+sum+"\n";
    QString information=id+" "+classnum+" "+name+" "+math+" "+eng+" "+phy;

    bool charge=name.length()<1||id.length()<9||math.length()<1||eng.length()<1||phy.length()<1;
    if(charge==1)
    {
        QMessageBox::critical(this,"Wrong","Incomplete information makes it impossible to modify","ok");
    }
    else
    {
         int ret=QMessageBox::question(this,"Be careful",messagebox_out,"ok","cancel");
         if(ret==0)
         {
         if(readfile()==-1)
         {
              this->close();
              QMessageBox::critical(this,"wrong","File reading failed, information not deleted","ok");
         }
         else
         {
            int i=0;
            for (i=0;i<score_line.length();i++)
            {
                QString line=score_line.at(i);
                line=line.trimmed();
                QStringList linesplit=line.split(" ");
                if(id!=linesplit.at(0))
                {
                     QFile file("score_temp.txt");
                     if(!file.open(QIODevice::Append|QIODevice::Text))
                     {
                         QMessageBox::critical(this,"wrong","File reading failed, information not changed","ok");
                         return;
                     }
                     QTextStream out(&file);
                     out<<line+"\n";
                     file.close();
                 }
              }
          QFile file_old("score.txt");
          QFile file_new("score_temp.txt");
          if (file_old.exists())
          {
            file_old.remove();
            file_new.rename("score.txt");
            writeIn(information);
          }
          else
          {
            QMessageBox::critical(this,"wrong","File reading failed, information not changed","ok");
          }
          QMessageBox::information(this,"notice","Change successfully","ok");
          this->close();
          }
          }
    }
}

void Modifystudent::on_btn_changedata_del_clicked()
{
    QString id=this->ui->le_addscore_id->text();
    readfile();
    int i=0;
    for (i=0;i<score_line.length();i++)
    {
        QString line=score_line.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
//        qDebug()<<i;
        if(id!=linesplit.at(0))
        {
            QFile file("score_temp.txt");
//            qDebug()<<id1;
            if(!file.open(QIODevice::Append|QIODevice::Text))
            {
               QMessageBox::critical(this,"wrong","Can't open the file","ok");
               return;
            }
        QTextStream out(&file);
        out<<line+"\n";
        file.close();
        }
    }
    QFile file_old("score.txt");
    QFile file_new("score_temp.txt");
    if (file_old.exists())
    {
       file_old.remove();
       file_new.rename("score.txt");
    }
    else
    {
       QMessageBox::critical(this,"wrong","No information is saved as a file and cannot be deleted","ok");
    }
    QMessageBox::information(this,"notice","successful deletion","ok");
    this->close();
}

void Modifystudent::on_btn_changedata_cancel_clicked()
{
    this->close();
}
