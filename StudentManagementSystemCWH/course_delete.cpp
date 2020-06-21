#include "course_delete.h"
#include "ui_course_delete.h"
#include<QMessageBox>
#include<QDebug>
#include<QFile>
course_delete::course_delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::course_delete)
{
    ui->setupUi(this);
}

course_delete::~course_delete()
{
    delete ui;
}

//退课功能
void course_delete::clearUserInterface()
{
    this->ui->lineEdit->clear();
}

int course_delete::readFromFile()
{
    //读取成绩文件
    QFile file("person_course.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        return -1;
    }
    QTextStream instuScore(&file);

    while(!instuScore.atEnd())
    {
        QString line = instuScore.readLine();
        module_line.append(line);
    }
    file.close();

    return 0;
}



void course_delete::delete_student_record()
{
        QString id=this->ui->lineEdit->text();

        int i=0;
        for (i=0;i<module_line.length();i++)
        {
            QString line=module_line.at(i);
            line=line.trimmed();
            QStringList linesplit=line.split(" ");

            if(id!=linesplit.at(1))
            {
                QFile file("person_course_temp.txt");
                if(!file.open(QIODevice::Append|QIODevice::Text))
                {
                   QMessageBox::critical(this,"wrong","fail to open the file","ok");
                   return;
                }
            QTextStream out(&file);
            out<<line+"\n";
            file.close();
            }
        }
        QFile file_old("person_course.txt");
        QFile file_new("person_course_temp.txt");
        if (file_old.exists())
        {
           file_old.remove();
           file_new.rename("person_course.txt");
        }
        else
        {
           QMessageBox::critical(this,"wrong","No information saved as file","ok");
        }
        //QMessageBox::information(this,"notice","delete successfully","ok");
}



void course_delete::on_delete_2_clicked()
{
    //QString cnt = this->ui->lineEdit->text();

    readFromFile();
    delete_student_record();
    QMessageBox::information(this,"Delete","message(s) has/have been deleted.");

}

void course_delete::on_back_clicked()
{
    this->hide();
}
