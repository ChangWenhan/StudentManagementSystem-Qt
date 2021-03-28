#include "tea_addscore.h"
#include "ui_tea_addscore.h"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
tea_addscore::tea_addscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tea_addscore)
{
    ui->setupUi(this);
}

tea_addscore::~tea_addscore()
{
    delete ui;
}


void tea_addscore::on_btn_addscore_add_clicked()
{
    QString name=this->ui->le_addscore_name->text();
    QString id=this->ui->le_addscore_id->text();
    QString classnum=this->ui->le_addscore_class->text();
    QString math=this->ui->le_addscore_math->text();
    QString eng=this->ui->le_addscore_eng->text();
    QString phy=this->ui->le_addscore_phy->text();    
    int temp=math.toInt()+eng.toInt()+phy.toInt();
    QString sum=QString::number(temp);
    QString messagebox_out="姓名："+name+"\n"+"学号："+id+"\n"+"班级："+classnum+"\n"+
            "数学："+math+"\n"+"英语："+eng+"\n"+"物理："+phy+"\n"+"总分："+sum+"\n";
    QString information=name+" "+id+" "+classnum+" "+math+" "+eng+" "+phy+" "+sum;

    bool charge=name.length()<1||id.length()<9||classnum.length()<6||
                math.length()<1||eng.length()<1||phy.length()<1||id.at(0)!="s";
    if(charge==1)
    {
        QMessageBox::critical(this,"错误","信息填写不完整，请检查","确定");
    }
    else
    {
       int ret=QMessageBox::question(this,"请确认",messagebox_out,"确认","取消");
       if(ret==0)
          {
             writeIn(information);
          }
    }
}

void tea_addscore::writeIn(QString information)
{
    this->ui->le_addscore_name->clear();
    this->ui->le_addscore_id->clear();
    this->ui->le_addscore_class->clear();
    this->ui->le_addscore_math->clear();
    this->ui->le_addscore_eng->clear();
    this->ui->le_addscore_phy->clear();
    this->ui->le_addscore_name->setFocus();
    QFile mFile("score.txt");
    if(!mFile.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有写入","确认");
        return;
    }
    QTextStream out(&mFile);
    out<<information<<"\n";
    mFile.flush();
    mFile.close();
}

void tea_addscore::on_btn_addscore_cancel_clicked()
{
    this->close();
}
