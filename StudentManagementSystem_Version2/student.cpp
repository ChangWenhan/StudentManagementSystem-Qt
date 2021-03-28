#include "student.h"
#include "ui_student.h"
#include "mainwindow.h"
#include "QDebug"
#include "QFile"
#include "QMessageBox"
#include "stu_course.h"
#include "mainwindow.h"

student::student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);

    if(readfile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","文件读取失败，无法进行查找","确认");
    }
}

student::~student()
{
    delete ui;
}

int student::readfile()
{
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

void student::on_btn_stu_query_clicked()
{
    for(int i=0;i<score_line.length();i++)
    {
        QString line=score_line.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
        if(account==linesplit.at(1))
        {
        QString messagebox_out="姓名："+linesplit.at(0)+"\n"+"学号："+linesplit.at(1)+"\n"
                               +"班级："+linesplit.at(2)+"\n"+"数学："+linesplit.at(3)+"\n"
                               +"英语："+linesplit.at(4)+"\n"+"物理："+linesplit.at(5)+"\n"
                               +"总分："+linesplit.at(6)+"\n";
        QMessageBox::information(this,"成绩显示",messagebox_out,"确认","取消");
        }
    }
}

void student::on_btn_stu_select_clicked()
{
    stu_course a;
    a.exec();
}

void student::on_pushButton_clicked()
{
    this->close();
}

void student::on_btn_return_clicked()
{
    this->close();
    MainWindow *main_window=new MainWindow;
    main_window->show();
}
