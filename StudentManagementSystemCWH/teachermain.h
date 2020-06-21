#ifndef TEACHERMAIN_H
#define TEACHERMAIN_H

#include <QDialog>
#include <QStackedLayout>
#include"selectstudent.h"
#include"sortstudent.h"
#include"modifystudent.h"
#include"teacherfunc.h"
#include"addstudent.h"
namespace Ui {
class TeacherMain;
}

class TeacherMain : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherMain(QWidget *parent = nullptr);
    ~TeacherMain();

private slots:
    void on_enterButton_clicked();

    void on_relogin_clicked();

private:
    Ui::TeacherMain *ui;
    teacherfunc cwhteacherfunc;
    teacherfunc *Teacherfunc;
    addstudent *Addstudent;//添加学生窗口
    Selectstudent *selectstudent;//查询窗口
    Modifystudent *modifystudent;//修改窗口
    Sortstudent *sortstudent;//排序窗口
    QStackedLayout *stackLayout; //QStackedLayout布局
};

#endif // TEACHERMAIN_H
