#include "tea_scoreimport.h"
#include "ui_tea_scoreimport.h"
#include "QFile"
#include "QTextStream"
#include "QStringList"
#include "QDebug"
#include "QMessageBox"
tea_scoreimport::tea_scoreimport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tea_scoreimport)
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

    this->ui->tableView->setColumnWidth(0,80);
    this->ui->tableView->setColumnWidth(1,120);
    this->ui->tableView->setColumnWidth(2,150);
    this->ui->tableView->setColumnWidth(3,100);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,100);
    this->ui->tableView->setColumnWidth(6,100);

    if(readfile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","文件读取失败","确认");
    }
}

tea_scoreimport::~tea_scoreimport()
{
    delete ui;
}

void tea_scoreimport::reset()
{
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("班级"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("数学"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("英语"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("物理"));
    this->model->setHorizontalHeaderItem(6,new QStandardItem("总分"));

    this->ui->tableView->setColumnWidth(0,80);
    this->ui->tableView->setColumnWidth(1,120);
    this->ui->tableView->setColumnWidth(2,150);
    this->ui->tableView->setColumnWidth(3,100);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,100);
    this->ui->tableView->setColumnWidth(6,100);
}

int tea_scoreimport::readfile()
{
    score_line.clear();
    QFile file("score.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    int row=0;
    while (!in.atEnd())
    {
        QString line=in.readLine();
        score_line.append(line);
        QStringList subs=line.split(" ");
        for(int i=0;i<subs.length();i++)
        {
           this->model->setItem(row,i,new QStandardItem(subs.at(i)));
        }
        row++;
    }
    file.close();
    return 0;
}

void tea_scoreimport::on_btn_dosort_clicked()
{
    this->model->clear();
    reset();
    readfile();
    int flag=this->ui->cbb_sortway->currentIndex();
    switch (flag) {
    case 0:
        model->sort(6,Qt::DescendingOrder);
        break;
    case 1:
        model->sort(3,Qt::DescendingOrder);
        break;
    case 2:
        model->sort(4,Qt::DescendingOrder);
        break;
    case 3:
        model->sort(5,Qt::DescendingOrder);
        break;
    case 4:
        model->sort(1,Qt::AscendingOrder);
        break;
    case 5:
        model->sort(2,Qt::AscendingOrder);
        break;
    default:
        break;
    }
}

void tea_scoreimport::on_btn_analyse_clicked()
{
    this->model->clear();
    reset();
    readfile();
    on_btn_dosort_clicked();
    double sum_math=0,sum_eng=0,sum_phy=0,sum=0;
    double pass_math=0,pass_eng=0,pass_phy=0;
    double ave_math=0,ave_eng=0,ave_phy=0,ave_sum=0;
    double var_math=0,var_eng=0,var_phy=0,var_sum=0;
    int row=this->model->rowCount();
    for(int i=0;i<row;i++)//计算数学总分和通过人数
    {
        QModelIndex index=model->index(i,3,QModelIndex());
        QString temp= index.data().toString();
        double one=temp.toDouble();
        sum_math+=one;
        if(one>=60)
        {
            pass_math++;
        }
    }
    for(int i=0;i<row;i++)//计算英语总分和通过人数
    {
        QModelIndex index=model->index(i,4,QModelIndex());
        QString temp= index.data().toString();
        double one=temp.toDouble();
        sum_eng+=one;
        if(one>=60)
        {
            pass_eng++;
        }
    }
    for(int i=0;i<row;i++)//计算物理总分和通过人数
    {
        QModelIndex index=model->index(i,5,QModelIndex());
        QString temp= index.data().toString();
        double one=temp.toDouble();
        sum_phy+=one;
        if(one>=60)
        {
            pass_phy++;
        }
    }
    for(int i=0;i<row;i++)//计算总分和
    {
        QModelIndex index=model->index(i,6,QModelIndex());
        QString temp= index.data().toString();
        double one=temp.toDouble();
        sum+=one;
    }

    pass_math/=row;pass_eng/=row;pass_phy/=row;
    ave_math=sum_math/row;ave_eng=sum_eng/row;ave_phy=sum_phy/row;ave_sum=sum/row;

    for(int i=0;i<row;i++)
    {
        QModelIndex index=model->index(i,3,QModelIndex());
        QString temp= index.data().toString();
        double one=temp.toDouble();
        var_math+=(one-ave_math)*(one-ave_math);
    }
    for(int i=0;i<row;i++)
    {
        QModelIndex index=model->index(i,4,QModelIndex());
        QString temp= index.data().toString();
        double one=temp.toDouble();
        var_eng+=(one-ave_eng)*(one-ave_eng);
    }
    for(int i=0;i<row;i++)
    {
        QModelIndex index=model->index(i,5,QModelIndex());
        QString temp= index.data().toString();
        double one=temp.toDouble();
        var_phy+=(one-ave_phy)*(one-ave_phy);
    }
    for(int i=0;i<row;i++)
    {
        QModelIndex index=model->index(i,6,QModelIndex());
        QString temp= index.data().toString();
        double one=temp.toDouble();
        var_sum+=(one-ave_sum)*(one-ave_sum);
    }

    var_math/=row;var_eng/=row;var_phy/=row;var_sum/=row;

    this->model->setItem(++row,0,new QStandardItem("及格率"));
    this->model->setItem(row,3,new QStandardItem(QString::number(pass_math)));
    this->model->setItem(row,4,new QStandardItem(QString::number(pass_eng)));
    this->model->setItem(row,5,new QStandardItem(QString::number(pass_phy)));
    this->model->setItem(++row,0,new QStandardItem("平均分"));
    this->model->setItem(row,3,new QStandardItem(QString::number(ave_math)));
    this->model->setItem(row,4,new QStandardItem(QString::number(ave_eng)));
    this->model->setItem(row,5,new QStandardItem(QString::number(ave_phy)));
    this->model->setItem(row,6,new QStandardItem(QString::number(ave_sum)));
    this->model->setItem(++row,0,new QStandardItem("方差"));
    this->model->setItem(row,3,new QStandardItem(QString::number(var_math)));
    this->model->setItem(row,4,new QStandardItem(QString::number(var_eng)));
    this->model->setItem(row,5,new QStandardItem(QString::number(var_phy)));
    this->model->setItem(row,6,new QStandardItem(QString::number(var_sum)));
}
