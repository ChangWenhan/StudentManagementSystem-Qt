#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "system.h"
#include "student.h"
#include "teacher.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

QString account;
QString password;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::readstudentfile()
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

int MainWindow::readteacherfile()
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

int MainWindow::readcontroller()
{
    QFile file("controller.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
       QString line=in.readLine();
       controller_line.append(line);
    }
    file.close();
    return 0;
}

void MainWindow::on_btn_denglu_clicked()
{
    account=this->ui->le_zhanghao->text();
    password=this->ui->le_mima->text();

    if(readstudentfile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","学生信息读取失败，\n学生账户无法登录，\n可登录管理员账户修改！","确认");
    }
    else if (readteacherfile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","教师信息读取失败，\n教师账户无法登录，\n可登录管理员账户修改！","确认");
    }

    int i=0,j=0,flag=100;

    if(account.at(0)=="s")
    {
    for (i=0;i<student_line.length();i++)
    {
        QString line=student_line.at(i);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
        if(account==linesplit.at(1)&&password==linesplit.at(2))
        {
        flag=0;
        }
    }
    }
    else if(account.at(0)=="t")
    {
    for (j=0;j<teacher_line.length();j++) {
        QString line=teacher_line.at(j);
        line=line.trimmed();
        QStringList linesplit=line.split(" ");
        if(account==linesplit.at(1)&&password==linesplit.at(2))
        {
           flag=1;
        }
    }
    }
    else if(account=="controller"&&password=="0000")
    {
        flag=2;
//    for (j=0;j<controller_line.length();j++) {
//        QString line=controller_line.at(j);
//        line=line.trimmed();
//        QStringList linesplit=line.split(" ");
//        if(account==linesplit.at(0)&&password==linesplit.at(1))
//        {
//           flag=2;
//        }
//    }
    }
    else if (account.length()<1||password.length()<1)
    {
        QMessageBox::critical(this,"错误","请输入账号和密码！","确认");
        flag=3;
    }

    switch (flag)
    {
    case 0:
    {
        student a;
        this->close();
        a.exec();
        break;
    }
    case 1:
    {
        teacher a;
        this->close();
        a.exec();
        break;
    }
    case 2:
    {
        class system a;
        this->close();
        a.exec();
        break;
    }
    case 3:
    {
        break;
    }
    default:
    {
        QMessageBox::critical(this,"错误","账号密码错误!\n或账号不存在!","确认");
        break;
    }
    }
}

void MainWindow::on_btn_tuichu_clicked()
{
    this->close();
}
