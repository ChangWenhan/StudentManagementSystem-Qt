#include "mdelete.h"
#include "ui_mdelete.h"
#include<QMessageBox>
#include <QDialog>
#include<QString>
#include<QList>
#include<QTextStream>
#include<QDebug>
#include<QFile>

mdelete::mdelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mdelete)
{
    ui->setupUi(this);
}

mdelete::~mdelete()
{
    delete ui;
}

void mdelete::on_pushButton_clicked()
{
    this->hide();
}

void mdelete::on_deletebutton_clicked()
{
    QString cnt = this->ui->le_ID->text();

    readFromFile();
    int n_deleted = delete_student_record(cnt);
    QString n ;
    n.setNum(n_deleted);
    QMessageBox::information(this,"删除","学号"+cnt+", "+ n +" 条信息已经删除了","确定");
}

void mdelete::clearUserInterface()
{
    this->ui->le_name->clear();
    this->ui->le_ID->clear();
    this->ui->le_class->clear();
    this->ui->le_passwd->clear();
    this->ui->le_name->setFocus();
    this->ui->comboBox->setCurrentText(0);
    this->ui->comboBox->setCurrentText(0);
    this->ui->comboBox->setCurrentText(0);
}

//删除老师信息功能
int mdelete::readFromFile()
{
    //读取成绩文件
    QFile file("teacher.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        return -1;
    }
    QTextStream instuScore(&file);

    while(!instuScore.atEnd())
    {
        QString line = instuScore.readLine();
        stuScore_lines.append(line);
    }
    file.close();

    return 0;
}

int mdelete::delete_student_record(QString cnt)
{
    int count = 0;
    //删除成绩
    int i = 0;
    for (i = 0; i<stuScore_lines.length();i++)
    {
        QString line = stuScore_lines.at(i);

        line.trimmed();
        QStringList subs = line.split(" ");

        if(cnt == subs.at(1))
        {
             //移除
          for(int j=i;j<stuScore_lines.length();j++)
          {
              stuScore_lines.removeAt(i);
          }
          count ++;
        }
    }
    writeToFile();
    return count;
}

void mdelete::writeToFile()
{
    //写入成绩
    QFile fileScore("teacher.txt");
    if(! fileScore.open(QIODevice::ReadWrite | QIODevice::Text ) )
    {
        QMessageBox::critical(this,"错误","文件打开失败","确定");
        return;
    }
    QTextStream outScore(&fileScore);
    for(int i=0;i<stuScore_lines.length();i++)
    {
      outScore<<stuScore_lines.at(i)<<"\n";
    }
    fileScore.close();
}


//删除学生信息功能
int mdelete::readFromFile_2()
{
    //读取成绩文件
    QFile file("message.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        return -1;
    }
    QTextStream instuScore(&file);

    while(!instuScore.atEnd())
    {
        QString line = instuScore.readLine();
        stuScore_lines.append(line);
    }
    file.close();

    return 0;
}

int mdelete::delete_student_record_2(QString cnt)
{
    int count = 0;
    //删除成绩
    int i = 0;
    for (i = 0; i<stuScore_lines.length();i++)
    {
        QString line = stuScore_lines.at(i);

        line.trimmed();
        QStringList subs = line.split(" ");

        if(cnt == subs.at(1))
        {
             //移除
          stuScore_lines.removeAt(i);
          count ++;
        }
    }
    writeToFile_2();
    return count;
}

void mdelete::writeToFile_2()
{
    //写入成绩
    QFile fileScore("message.txt");
    if(! fileScore.open(QIODevice::ReadWrite | QIODevice::Text ) )
    {
        QMessageBox::critical(this,"错误","文件打开失败","确定");
        return;
    }
    QTextStream outScore(&fileScore);
    for(int i=0;i<stuScore_lines.length();i++)
    {
      outScore<<stuScore_lines.at(i)<<"\n";
    }
    fileScore.close();
}


//修改信息功能
void mdelete::writeToFile(QString cnt)
{
    QFile file("message.txt");
    if(! file.open(QIODevice::ReadWrite | QIODevice::Text ) )
    {
        QMessageBox::critical(this,"wrong","fail to open the file","OK");
        return;
    }

    QTextStream out(&file);
    out<<cnt;
    file.close();
}

void mdelete::writeToFile_2(QString cnt)
{
    QFile file("teacher.txt");
    if(! file.open(QIODevice::ReadWrite | QIODevice::Text ) )
    {
        QMessageBox::critical(this,"wrong","fail to open the file","OK");
        return;
    }

    QTextStream out(&file);
    out<<cnt;
    file.close();
}

void mdelete::on_modifybutton_clicked()
{
    QString rnt = this->ui->le_ID->text();
    QString num=this->ui->le_class->text();

    if(num.length()!=0)
    {
        readFromFile_2();
        int n_deleted = delete_student_record_2(rnt);
        QString n ;
        n.setNum(n_deleted);
        QMessageBox::information(this,"删除","学号"+rnt+", "+ n +" 条信息已经修改了","确定");
    }
    else if (num.length()==0) {
        readFromFile();
        int n_deleted = delete_student_record(rnt);
        QString n ;
        n.setNum(n_deleted);
        QMessageBox::information(this,"删除","工号"+rnt+", "+ n +" 条信息已经修改了","确定");
    }



    QString name=this->ui->le_name->text();
    QString id=this->ui->le_ID->text();
    QString sex=this->ui->comboBox_3->currentText();
    QString age=this->ui->comboBox->currentText();
    QString major=this->ui->comboBox_2->currentText();
    QString classnum=this->ui->le_class->text();
    QString passwd=this->ui->le_passwd->text();
    QString content=name+"\n"+id+"\n"+age+"\n"+sex+"\n"+major+"\n"+passwd;

    QString cnt=name+" "+id+" "+sex+" "+age+" "+major+" "+classnum+" "+passwd+"\n";
    QString cnt2=name+" "+id+" "+sex+" "+age+" "+major+" "+passwd+"\n";




    if(name.length()<1 || id.length()<1 ||passwd.length()<6){
        QMessageBox::critical(this,"WRONG","Incomplete necessary information");
    }
    else
    {
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
