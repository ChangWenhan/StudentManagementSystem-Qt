#ifndef COURSE_DELETE_H
#define COURSE_DELETE_H

#include <QDialog>

namespace Ui {
class course_delete;
}

class course_delete : public QDialog
{
    Q_OBJECT

public:
    explicit course_delete(QWidget *parent = nullptr);
    ~course_delete();

    //删除用的函数
    int readFromFile();

    void delete_student_record();

    void clearUserInterface();
private slots:
    void on_delete_2_clicked();

    void on_back_clicked();

private:
    Ui::course_delete *ui;
    QList<QString> module_line;
};

#endif // COURSE_DELETE_H
