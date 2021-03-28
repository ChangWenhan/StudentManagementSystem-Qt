#ifndef SYSDEL_H
#define SYSDEL_H

#include <QDialog>

extern QString ID;

namespace Ui {
class sysdel;
}

class sysdel : public QDialog
{
    Q_OBJECT

public:
    explicit sysdel(QWidget *parent = nullptr);
    int readstudentfile();
    int readteacherfile();
    int readcoursefile();
    void deletestudent();
    void deleteteacher();
    void deletecourse();
//    ~sysdel();

private slots:
    void on_btn_del_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::sysdel *ui;
    QList<QString> student_line;
    QList<QString> teacher_line;
    QList<QString> course_line;
};

#endif // SYSDEL_H
