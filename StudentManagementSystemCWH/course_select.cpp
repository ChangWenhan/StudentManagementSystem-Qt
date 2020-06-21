#include "course_select.h"
#include "ui_course_select.h"
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

course_select::course_select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::course_select)
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

course_select::~course_select()
{
    delete ui;
}

int course_select::readfile()//读取文件
{
    QFile file("module.txt");
//文件不能读取则返回-1，用于下一步操作的判断
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return -1;
    }
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line=in.readLine();
            course_line.append(line);
        }
        file.close();
      return 0;
}

void course_select::initialization()//设置标头
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

void course_select::on_button_find_clicked()
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

void course_select::display(int row, QStringList course_line)
{
    int i=0;
    for (i=0;i<course_line.length();i++) {
        this->model->setItem(row,i,new QStandardItem(course_line.at(i)));
    }
}




void course_select::on_button_select_clicked()
{
    QString course_infor;
        int cur_row = ui-> tableView ->currentIndex().row();
        if(row[cur_row]==-1){
            QMessageBox::critical(this,"Wrong","Can't select twice","OK");
        }
        else
        {
    //判断是否能打开文档
            QFile file("person_course.txt");
            if(!file.open(QIODevice::Append|QIODevice::Text)){
            QMessageBox::critical(this,"Wrong","fail to open the file","OK");
            return;
            }
            int i=0;
            for (i=0;i<6;i++)
            {
                QModelIndex index=model->index(cur_row,i,QModelIndex());
                QString qs_get= index.data().toString();
                course_infor=course_infor+qs_get;
                course_infor=course_infor+" ";
            }
            course_infor=course_infor+"\n";
    //写入
            QTextStream out(&file);
            out<<course_infor;
            file.close();
            row[cur_row]=-1;
        } 
}
