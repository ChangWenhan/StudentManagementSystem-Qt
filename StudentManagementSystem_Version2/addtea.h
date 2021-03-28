#ifndef ADDTEA_H
#define ADDTEA_H

#include <QDialog>

namespace Ui {
class addtea;
}

class addtea : public QDialog
{
    Q_OBJECT

public:
    explicit addtea(QWidget *parent = nullptr);
    void writeIn(QString info);
    ~addtea();

private slots:
    void on_btn_sys_addtea_clicked();

    void on_btn_sys_addteacancel_clicked();

private:
    Ui::addtea *ui;
};

#endif // ADDTEA_H
