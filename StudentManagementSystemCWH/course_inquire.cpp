#include "course_inquire.h"
#include "ui_course_inquire.h"
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<QPushButton>
#include<QFile>
#include<QTextStream>
#include<QIODevice>
#include<QStringList>
#include<QStandardItem>
#include<QStandardItemModel>
#include<QtMath>
#include<QCheckBox>
#include<QAbstractItemView>
#include<QDialog>
#include<QList>


course_inquire::course_inquire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::course_inquire)
{
    ui->setupUi(this);
    if(readfile()==-1){
            this->close();
            QMessageBox::critical(this,"Wrong","cail to open the file","OK");
        }
    this->model = new QStandardItemModel;
    initialization();
    this->ui->tableView->setModel(model);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

course_inquire::~course_inquire()
{
    delete ui;
}



//查看选中的课程
void course_inquire::initialization()//设置标头
{
    this->model->setHorizontalHeaderItem(0,new QStandardItem("课程名称."));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("课程编号."));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("开课学院."));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("学分设置."));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("学时设置."));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("选课班级."));

    this->ui->tableView->setColumnWidth(0,180);
    this->ui->tableView->setColumnWidth(1,200);
    this->ui->tableView->setColumnWidth(2,180);
    this->ui->tableView->setColumnWidth(3,100);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,180);
}

int course_inquire::readfile()//读取文件
{
    QFile file("person_course.txt");
//文件不能读取则返回-1，用于下一步操作的判断
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
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

void course_inquire::display(int row, QStringList course_line)
{
    int i=0;
    for (i=0;i<course_line.length();i++) {
        this->model->setItem(row,i,new QStandardItem(course_line.at(i)));
    }
}

void course_inquire::on_inquirebtn_clicked() //查询选中的课程
{
    this->model->clear();
        //initialization();
            //for循环将每行字符串切割并比较和输入是否相等，
    int i=0,row=0;
    for (i=0;i<course_line.length();i++)
    {
        QString line = course_line.at(i);

        line=line.trimmed();
        QStringList linesplit=line.split(" ");

        display(row++, linesplit);
    }
}

int course_inquire::readFromFile()
{
    QFile file("score.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return-1;
    }
    QTextStream in(&file);

    while(!in.atEnd()){
        QString line=in.readLine();
        stu_lines.append(line);
    }
    file.close();

    int i=0;
    for(i=0;i<stu_lines.length();i++)
    {
        qDebug()<<stu_lines.at(i);
    }

    return 0;
}

void course_inquire::doQuert(QString cnt)
{
    readFromFile();
    int i=0;
    int row=0;
    for(i=0;i<stu_lines.length();i++)
    {
        QString line=stu_lines.at(i);
        line=line.trimmed();//去掉开头结尾的空白
        QStringList  subs=line.split(" ");
        subs.at(0);
        if(cnt==subs.at(0))
            {
                disPlay(row++,subs);
            }
    }

}

void course_inquire::disPlay(int row, QStringList subs)
{
    int i=0;
    for(i=0;i<subs.length();i++)
    {
        this->model->setItem(row,i,new QStandardItem(subs.at(i)));
    }
}

void course_inquire::on_searchscore_clicked()
{
    QString cnt=this->ui->account->text();
    doQuert(cnt);
}

void course_inquire::on_pushButton_clicked()
{
    this->hide();
}



void course_inquire::on_deletecourse_clicked()
{
    readcourseFile();
    delete_student_record();
    clearUserInterface();
    QMessageBox::information(this,"Delete","message(s) has/have been deleted.");
}



void course_inquire::clearUserInterface()
{
    this->ui->class_num->clear();
}



int course_inquire::readcourseFile()
{
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



void course_inquire::delete_student_record()
{
        QString name=this->ui->class_num->text();

        int i=0;
        for (i=0;i<module_line.length();i++)
        {
            QString line=module_line.at(i);
            line=line.trimmed();
            QStringList linesplit=line.split(" ");

            if(name!=linesplit.at(1))
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
}
