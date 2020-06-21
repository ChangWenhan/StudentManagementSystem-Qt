#include "selectstudent.h"
#include "ui_selectstudent.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include<QStringList>
#include<QIODevice>
#include<QTextStream>
#include<QList>
#include<QString>
#include<QStandardItem>
#include<QStandardItemModel>

Selectstudent::Selectstudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selectstudent)
{
    ui->setupUi(this);
    if (readFromFile()==-1){
        QMessageBox::critical(this,"warning","fail to open the file");
        this->close();
    }
    this->model=new QStandardItemModel;
    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("班级"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("数学成绩"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("英语成绩"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("C++成绩"));
    this->ui->tableView->setModel(model);
}

Selectstudent::~Selectstudent()
{
    delete ui;
}

int Selectstudent::readFromFile()
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


void Selectstudent::on_returnbutton_clicked()
{
    this->hide();
}

void Selectstudent::on_selectbutton_clicked()
{
    int index = this->ui->combobox->currentIndex();
    QString cnt=this->ui->lineid->text();
    doQuert(index,cnt);
}

void Selectstudent::doQuert(int index, QString cnt)
{
    int i=0;
    int row=0;
    for(i=0;i<stu_lines.length();i++)
    {
        QString line=stu_lines.at(i);

        line=line.trimmed();//去掉开头结尾的空白
        QStringList  subs=line.split(" ");

        subs.at(0);
        switch(index){
        case(1):
            if(cnt==subs.at(2))
            {
                disPlay(row++,subs);
            }
            break;
        case(2):
            if(cnt==subs.at(0))
            {
                disPlay(row++,subs);
            }
            break;
        default:
            break;
        }
    }
}

void Selectstudent::disPlay(int row, QStringList subs)
{
    int i=0;
    for(i=0;i<subs.length();i++)
    {
        this->model->setItem(row,i,new QStandardItem(subs.at(i)));
    }
}

void Selectstudent::on_pushButton_clicked()
{
    this->hide();
}
