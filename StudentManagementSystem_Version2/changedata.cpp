#include "changedata.h"
#include "ui_changedata.h"
#include "QString"
#include "tea_querystu.h"
#include "QDebug"
#include "QMessageBox"
#include "QFile"

changedata::changedata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changedata)
{
    ui->setupUi(this);

    if(readfile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","文件读取失败!","确认");
    }
}

changedata::~changedata()
{
    delete ui;
}

int changedata::readfile()
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
    return 0;
}

void changedata::writeIn(QString information)
{
    this->ui->le_addscore_name->clear();
    this->ui->le_addscore_id->clear();
    this->ui->le_addscore_class->clear();
    this->ui->le_addscore_math->clear();
    this->ui->le_addscore_eng->clear();
    this->ui->le_addscore_phy->clear();
    this->ui->le_addscore_name->setFocus();
    QFile mFile("score.txt");
    if(!mFile.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有写入","确认");
        return;
    }
    QTextStream out(&mFile);
    out<<information<<"\n";
    mFile.flush();
    mFile.close();
}

void changedata::on_pushButton_clicked()
{
    this->ui->le_addscore_name->setText(name1);
    this->ui->le_addscore_id->setText(id1);
    this->ui->le_addscore_class->setText(classname1);
    this->ui->le_addscore_math->setText(math1);
    this->ui->le_addscore_eng->setText(eng1);
    this->ui->le_addscore_phy->setText(phy1);
}

void changedata::on_btn_changedata_change_clicked()
{
    QString name=this->ui->le_addscore_name->text();
    QString id=this->ui->le_addscore_id->text();
    QString classnum=this->ui->le_addscore_class->text();
    QString math=this->ui->le_addscore_math->text();
    QString eng=this->ui->le_addscore_eng->text();
    QString phy=this->ui->le_addscore_phy->text();
    int temp=math.toInt()+eng.toInt()+phy.toInt();
    QString sum=QString::number(temp);
    QString messagebox_out="姓名："+name+"\n"+"学号："+id+"\n"+"班级："+classnum+"\n"+
            "数学："+math+"\n"+"英语："+eng+"\n"+"物理："+phy+"\n"+"总分："+sum+"\n";
    QString information=name+" "+id+" "+classnum+" "+math+" "+eng+" "+phy+" "+sum;

    bool charge=name.length()<1||id.length()<9||classnum.length()<6||
                math.length()<1||eng.length()<1||phy.length()<1;
    if(charge==1)
    {
        QMessageBox::critical(this,"错误","信息填写不完整，无法修改！","确定");
    }
    else
    {
         int ret=QMessageBox::question(this,"请确认",messagebox_out,"确认","取消");
         if(ret==0)
         {
         if(readfile()==-1)
         {
              this->close();
              QMessageBox::critical(this,"错误","文件读取失败，信息没有删除","确认");
         }
         else
         {
            int i=0;
            for (i=0;i<score_line.length();i++)
            {
                QString line=score_line.at(i);
                line=line.trimmed();
                QStringList linesplit=line.split(" ");
                if(id!=linesplit.at(1))
                {
                     QFile file("score_temp.txt");
                     if(!file.open(QIODevice::Append|QIODevice::Text))
                     {
                         QMessageBox::critical(this,"错误","文件打开失败，信息没有修改","确认");
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
            QMessageBox::critical(this,"错误","未有信息保存为文件，无法修改","确认");
          }
          QMessageBox::information(this,"通知","修改成功！","确认");
          this->close();
          }
          }
    }
}

void changedata::on_btn_changedata_del_clicked()
{
    readfile();
    int i=0;
    for (i=0;i<score_line.length();i++)
    {
        QString line=score_line.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
//        qDebug()<<i;
        if(id1!=linesplit.at(1))
        {
            QFile file("score_temp.txt");
//            qDebug()<<id1;
            if(!file.open(QIODevice::Append|QIODevice::Text))
            {
               QMessageBox::critical(this,"错误","文件打开失败，信息没有写入","确认");
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
       QMessageBox::critical(this,"错误","未有信息保存为文件，无法删除","确认");
    }
    QMessageBox::information(this,"通知","删除成功！","确认");
    this->close();
}

void changedata::on_btn_changedata_cancel_clicked()
{
    this->close();
}
