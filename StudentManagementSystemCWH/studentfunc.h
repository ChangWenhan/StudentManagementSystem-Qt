#ifndef STUDENTFUNC_H
#define STUDENTFUNC_H

#include <QDialog>

namespace Ui {
class StudentFunc;
}

class StudentFunc : public QDialog
{
    Q_OBJECT

public:
    explicit StudentFunc(QWidget *parent = nullptr);
    ~StudentFunc();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_course_delete_clicked();

private:
    Ui::StudentFunc *ui;
};

#endif // STUDENTFUNC_H
