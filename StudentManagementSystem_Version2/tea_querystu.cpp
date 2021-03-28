#include "tea_querystu.h"
#include "ui_tea_querystu.h"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "QDebug"
#include "changedata.h"

QString name1;
QString id1;
QString classname1;
QString math1;
QString eng1;
QString phy1;

tea_querystu::tea_querystu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tea_querystu)
{
    ui->setupUi(this);

    this->model=new QStandardItemModel;

    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("班级"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("数学"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("英语"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("物理"));
    this->model->setHorizontalHeaderItem(6,new QStandardItem("总分"));

    this->ui->tableView->setModel(model);

    this->ui->tableView->setColumnWidth(0,60);
    this->ui->tableView->setColumnWidth(1,120);
    this->ui->tableView->setColumnWidth(2,100);
    this->ui->tableView->setColumnWidth(3,80);
    this->ui->tableView->setColumnWidth(4,80);
    this->ui->tableView->setColumnWidth(5,80);
    this->ui->tableView->setColumnWidth(6,80);

//    int row=this->ui->tableView->currentIndex().row();
//    model->removeRow(row);
//    model->submit();

    if(readfile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","文件读取失败，无法进行查找","确认");
    }
}

tea_querystu::~tea_querystu()
{
    delete ui;
}

void tea_querystu::reset()
{
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("班级"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("数学"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("英语"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("物理"));
    this->model->setHorizontalHeaderItem(6,new QStandardItem("总分"));
    this->ui->tableView->setColumnWidth(0,60);
    this->ui->tableView->setColumnWidth(1,120);
    this->ui->tableView->setColumnWidth(2,100);
    this->ui->tableView->setColumnWidth(3,80);
    this->ui->tableView->setColumnWidth(4,80);
    this->ui->tableView->setColumnWidth(5,80);
    this->ui->tableView->setColumnWidth(6,80);
}

int tea_querystu::readfile()
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
//        qDebug()<<line;
    }
    file.close();
    return 0;
}

void tea_querystu::display(int row, QStringList score_line)
{
    int i=0;
    for (i=0;i<score_line.length();i++)
    {
        this->model->setItem(row,i,new QStandardItem(score_line.at(i)));
    }
}

void tea_querystu::on_btn_doquery_clicked()
{
    this->model->clear();
    reset();
    readfile();
    int flag=this->ui->cbb_querymode->currentIndex();
    QString infor=this->ui->le_info->text();

    if (infor.length()<1)
    {
            QMessageBox::critical(this,"错误","输入信息错误，请重试！","确认");
    }
    else
    {
//            qDebug()<<flag;
            int i=0,row=0;
            for (i=0;i<score_line.length();i++)
            {
                QString line=score_line.at(i);
                line=line.trimmed();
                QStringList linesplit=line.split(" ");
                switch (flag)
                {
                case 0:
                    if(linesplit.at(0).contains(infor,Qt::CaseSensitive))
                    {
                        display(row++, linesplit);
//                        qDebug()<<1;
                    }
                    break;
                case 1:
                    if(linesplit.at(1).contains(infor,Qt::CaseSensitive))
                    {
                         display(row++, linesplit);
//                         qDebug()<<2;
                    }
                    break;
                case 2:
                    if(linesplit.at(2).contains(infor,Qt::CaseSensitive))
                    {
                         display(row++, linesplit);
//                         qDebug()<<3;
                    }
                break;
                default:break;
                }
            }
    }
}

void tea_querystu::on_tableView_doubleClicked(const QModelIndex &index)
{
    changedata a;
    int row=this->ui->tableView->currentIndex().row();
    name1=model->data(model->index(row,0)).toString();
    id1=model->data(model->index(row,1)).toString();
    classname1=model->data(model->index(row,2)).toString();
    math1=model->data(model->index(row,3)).toString();
    eng1=model->data(model->index(row,4)).toString();
    phy1=model->data(model->index(row,5)).toString();
//    sum1=model->data(model->index(row,6)).toString();
    a.exec();
}












