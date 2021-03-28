#ifndef ADDCOURSE_H
#define ADDCOURSE_H

#include <QDialog>

namespace Ui {
class addcourse;
}

class addcourse : public QDialog
{
    Q_OBJECT

public:
    explicit addcourse(QWidget *parent = nullptr);
    void writeIn(QString info);
    ~addcourse();

private slots:
    void on_btn_sys_addcou_clicked();

    void on_btn_sys_addcoucancel_clicked();

private:
    Ui::addcourse *ui;
};

#endif // ADDCOURSE_H
