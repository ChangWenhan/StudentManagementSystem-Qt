#ifndef STUDENT_H
#define STUDENT_H

#include <QDialog>

namespace Ui {
class student;
}

class student : public QDialog
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = nullptr);
    int readfile();
    ~student();

private slots:
    void on_btn_stu_query_clicked();

    void on_btn_stu_select_clicked();

    void on_pushButton_clicked();

    void on_btn_return_clicked();

private:
    Ui::student *ui;
    QList<QString> score_line;
};

#endif // STUDENT_H
