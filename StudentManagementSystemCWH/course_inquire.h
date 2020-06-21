#ifndef COURSE_INQUIRE_H
#define COURSE_INQUIRE_H
#include<QMessageBox>
#include<QString>
#include<QList>
#include<QTextStream>
#include <QDialog>
#include<QStandardItem>
#include<QStandardItemModel>

namespace Ui {
class course_inquire;
}

class course_inquire : public QDialog
{
    Q_OBJECT

public:
    explicit course_inquire(QWidget *parent = nullptr);
    ~course_inquire();
    void initialization();
    void display(int row,QStringList score_line);
    int readfile();

    //删除用的函数
    //int readFromFile();

    //void writeToFile();

    //int delete_student_record(QString cnt);

    //void clearUserInterface();

    int readFromFile();

    void doQuert(QString cnt);

    void disPlay(int row,QStringList subs);

    int readcourseFile();

    void scorehead();

    void delete_student_record();

    void clearUserInterface();
private slots:
    void on_inquirebtn_clicked();

    //void on_deletebtn_clicked();

    void on_pushButton_clicked();

    void on_searchscore_clicked();

    void on_deletecourse_clicked();


private:
    Ui::course_inquire *ui;

    QStandardItemModel *model;

    QList<QString> course_line;

    QList<QString> cus_lines;

    int row[20]={0};


    QList<QString> stu_lines;

    QList<QString> module_line;

};

#endif // COURSE_INQUIRE_H
