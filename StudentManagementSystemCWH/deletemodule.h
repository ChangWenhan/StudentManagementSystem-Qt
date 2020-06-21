#ifndef DELETEMODULE_H
#define DELETEMODULE_H

#include <QDialog>

namespace Ui {
class deletemodule;
}

class deletemodule : public QDialog
{
    Q_OBJECT

public:

    explicit deletemodule(QWidget *parent = nullptr);
    ~deletemodule();
    int readcoursefile();
    void deletecourse();


private slots:
//   void on_backbutton_clicked();



    void on_btn_del_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::deletemodule *ui;
    QList<QString> course_line;

    //QList<QString> student_line; //存储学生
    //QList<QString> stuScore_lines;  //存储学生成绩


};

#endif // DELETEMODULE_H
