#ifndef MDELETE_H
#define MDELETE_H

#include <QDialog>

namespace Ui {
class mdelete;
}

class mdelete : public QDialog
{
    Q_OBJECT

public:
    explicit mdelete(QWidget *parent = nullptr);
    ~mdelete();

    int readFromFile();

    int readFromFile_2();

    void writeToFile();

    void writeToFile_2();

    int delete_student_record(QString cnt);

    int delete_student_record_2(QString cnt);

    void writeToFile(QString cnt);

    void writeToFile_2(QString cnt);


private slots:
    void on_pushButton_clicked();

    void on_deletebutton_clicked();

    void on_modifybutton_clicked();

    void clearUserInterface();

private:
    Ui::mdelete *ui;
    QList<QString> stu_lines; //存储学生
    QList<QString> stuScore_lines;  //存储学生成绩
};

#endif // MDELETE_H
