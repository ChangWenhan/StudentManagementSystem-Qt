#include "deletemodule.h"
#include "ui_deletemodule.h"
#include "QMessageBox"
#include "QDebug"
#include "QFile"

//QString ID;

deletemodule::deletemodule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletemodule)
{
    ui->setupUi(this);

    if(readcoursefile()==1)
    {
        this->close();
        QMessageBox::critical(this,"wrong","fail to read the file","ok");
    }
}

deletemodule::~deletemodule()
{
    delete ui;
}



int deletemodule::readcoursefile()
{
    QFile file("module.txt");
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

void deletemodule::deletecourse()
{

    QString ID=this->ui->le_id->text();
    //QString ID=this->ui->le_id->text()；
    int i=0;
    for (i=0;i<course_line.length();i++)
        {
            QString line=course_line.at(i);
            line=line.trimmed();
            QStringList linesplit=line.split(" ");
            if(ID!=linesplit.at(1))
            {
                QFile file("module_temp.txt");
                if(!file.open(QIODevice::Append|QIODevice::Text))
                {
                   QMessageBox::critical(this,"wrong","fail to open then file","ok");
                   return;
                }
            QTextStream out(&file);
            out<<line+"\n";
            file.close();
            }
        }
        QFile file_old("module.txt");
        QFile file_new("module_temp.txt");
        if (file_old.exists())
        {
           file_old.remove();
           file_new.rename("module.txt");
        }
        else
        {
           QMessageBox::critical(this,"wrong","there is no information saved in file","ok");
        }
        QMessageBox::information(this,"notice","delete successfully","ok");
}

void deletemodule::on_btn_del_clicked()
{
    //QString ID=this->ui->le_id->text();
    readcoursefile();
    deletecourse();
}

void deletemodule::on_btn_cancel_clicked()
{
    this->close();
}
