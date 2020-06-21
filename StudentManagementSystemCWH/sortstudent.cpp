#include "sortstudent.h"
#include "ui_sortstudent.h"
#include "QFile"
#include "QTextStream"
#include "QStringList"
#include "QDebug"
#include "QMessageBox"

Sortstudent::Sortstudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sortstudent)
{
    ui->setupUi(this);
    this->model=new QStandardItemModel;

    this->model->setHorizontalHeaderItem(0,new QStandardItem("学号."));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("班级."));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("数学"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("英语"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("C++"));

    this->ui->tableView->setModel(model);

    this->ui->tableView->setColumnWidth(0,150);
    this->ui->tableView->setColumnWidth(1,120);
    this->ui->tableView->setColumnWidth(2,150);
    this->ui->tableView->setColumnWidth(3,100);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,100);

    if(readfile()==-1)
    {
        this->close();
        QMessageBox::critical(this,"错误","文件读取失败","确认");
    }
}

Sortstudent::~Sortstudent()
{
    delete ui;
}

int Sortstudent::readfile()
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


void Sortstudent::on_btn_dosort_clicked()
{
    int flag=this->ui->cbb_sortway->currentIndex();
    switch (flag) {

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
        model->sort(0,Qt::AscendingOrder);
        break;
    case 5:
        model->sort(1,Qt::DescendingOrder);
        break;
    default:
        break;
    }
}

void Sortstudent::on_btn_analyse_clicked()
{
    double sum_math=0,sum_eng=0,sum_phy=0;
    double pass_math=0,pass_eng=0,pass_phy=0;
    double ave_math=0,ave_eng=0,ave_phy=0;
    double var_math=0,var_eng=0,var_phy=0;

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

    pass_math/=row;pass_eng/=row;pass_phy/=row;
    ave_math=sum_math/row;ave_eng=sum_eng/row;ave_phy=sum_phy/row;

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

    var_math/=row;var_eng/=row;var_phy/=row;

    this->model->setItem(++row,0,new QStandardItem("学科通过."));
    this->model->setItem(row,3,new QStandardItem(QString::number(pass_math)));
    this->model->setItem(row,4,new QStandardItem(QString::number(pass_eng)));
    this->model->setItem(row,5,new QStandardItem(QString::number(pass_phy)));
    this->model->setItem(++row,0,new QStandardItem("学科平均."));
    this->model->setItem(row,3,new QStandardItem(QString::number(ave_math)));
    this->model->setItem(row,4,new QStandardItem(QString::number(ave_eng)));
    this->model->setItem(row,5,new QStandardItem(QString::number(ave_phy)));
    this->model->setItem(++row,0,new QStandardItem("方差."));
    this->model->setItem(row,3,new QStandardItem(QString::number(var_math)));
    this->model->setItem(row,4,new QStandardItem(QString::number(var_eng)));
    this->model->setItem(row,5,new QStandardItem(QString::number(var_phy)));

}
