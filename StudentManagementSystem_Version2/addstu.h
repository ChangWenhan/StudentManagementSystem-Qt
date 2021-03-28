#ifndef ADDSTU_H
#define ADDSTU_H

#include <QDialog>

namespace Ui {
class addstu;
}

class addstu : public QDialog
{
    Q_OBJECT

public:
    explicit addstu(QWidget *parent = nullptr);
    void writeIn(QString info);
    ~addstu();

private slots:
    void on_btn_sys_addstu_clicked();

    void on_btn_sys_addstu_cancel_clicked();

private:
    Ui::addstu *ui;
};

#endif // ADDSTU_H
