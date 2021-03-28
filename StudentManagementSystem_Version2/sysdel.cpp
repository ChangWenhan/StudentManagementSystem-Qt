#include "sysdel.h"
#include "ui_sysdel.h"
#include "QMessageBox"
#include "QDebug"
#include "QFile"

QString ID;

sysdel::sysdel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sysdel)
{
    ui->setupUi(this);

    if(readstudentfile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","文件读取失败!","确认");
    }

    if(readteacherfile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","文件读取失败!","确认");
    }

    if(readcoursefile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","文件读取失败!","确认");
    }
}

//sysdel::~sysdel()
//{
//    delete ui;
//}

int sysdel::readstudentfile()
{
    QFile file("student.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
       QString line=in.readLine();
       student_line.append(line);
    }
    file.close();
    return 0;
}

int sysdel::readteacherfile()
{
    QFile file("teacher.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
       QString line=in.readLine();
       teacher_line.append(line);
    }
    file.close();
    return 0;
}

int sysdel::readcoursefile()
{
    QFile file("course.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
       QString line=in.readLine();
       course_line.append(line);
    }
    file.close();
    return 0;
}

void sysdel::deletestudent()
{
    int i=0;
    for (i=0;i<student_line.length();i++)
    {
        QString line=student_line.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
        if(ID!=linesplit.at(1))
        {
            QFile file("student_temp.txt");
            if(!file.open(QIODevice::Append|QIODevice::Text))
            {
               QMessageBox::critical(this,"错误","文件打开失败，学生账号未删除","确认");
               return;
            }
        QTextStream out(&file);
        out<<line+"\n";
        file.close();
        }
    }
    QFile file_old("student.txt");
    QFile file_new("student_temp.txt");
    if (file_old.exists())
    {
       file_old.remove();
       file_new.rename("student.txt");
    }
    else
    {
       QMessageBox::critical(this,"错误","未有信息保存为文件，无法删除","确认");
    }
    QMessageBox::information(this,"通知","删除成功！","确认");
}

void sysdel::deleteteacher()
{
    int i=0;
    for (i=0;i<teacher_line.length();i++)
    {
        QString line=teacher_line.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
        if(ID!=linesplit.at(1))
        {
            QFile file("teacher_temp.txt");
            if(!file.open(QIODevice::Append|QIODevice::Text))
            {
               QMessageBox::critical(this,"错误","文件打开失败，教师账号未删除","确认");
               return;
            }
        QTextStream out(&file);
        out<<line+"\n";
        file.close();
        }
    }
    QFile file_old("teacher.txt");
    QFile file_new("teacher_temp.txt");
    if (file_old.exists())
    {
       file_old.remove();
       file_new.rename("teacher.txt");
    }
    else
    {
       QMessageBox::critical(this,"错误","未有信息保存为文件，无法删除","确认");
    }
    QMessageBox::information(this,"通知","删除成功！","确认");
}

void sysdel::deletecourse()
{
    int i=0;
    for (i=0;i<course_line.length();i++)
    {
        QString line=course_line.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
        if(ID!=linesplit.at(1))
        {
            QFile file("course_temp.txt");
            if(!file.open(QIODevice::Append|QIODevice::Text))
            {
               QMessageBox::critical(this,"错误","文件打开失败，课程信息未删除","确认");
               return;
            }
        QTextStream out(&file);
        out<<line+"\n";
        file.close();
        }
    }
    QFile file_old("course.txt");
    QFile file_new("course_temp.txt");
    if (file_old.exists())
    {
       file_old.remove();
       file_new.rename("course.txt");
    }
    else
    {
       QMessageBox::critical(this,"错误","未有信息保存为文件，无法删除","确认");
    }
    QMessageBox::information(this,"通知","删除成功！","确认");
}

void sysdel::on_btn_del_clicked()
{
    ID=this->ui->le_id->text();
    int flag=100;
    if(ID.at(0)=="s"&&ID.length()==9)
    {
        flag=0;
    }
    else if(ID.at(0)=="t"&&ID.length()==9)
    {
        flag=1;
    }
    else if(ID.length()==4)
    {
        flag=2;
    }
    else
    {
        QMessageBox::critical(this,"错误","ID填写错误或不完整，请修改！","确定");
    }
    switch (flag)
    {
    case 0:
        deletestudent();
        break;
    case 1:
        deleteteacher();
        break;
    case 2:
        deletecourse();
        break;
    default:
        break;
    }
}

void sysdel::on_btn_cancel_clicked()
{
    this->close();
}
