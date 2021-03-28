#ifndef SYSTEM_H
#define SYSTEM_H

#include <QDialog>

namespace Ui {
class system;
}

class system : public QDialog
{
    Q_OBJECT

public:
    explicit system(QWidget *parent = nullptr);
    ~system();

private slots:
    void on_btn_addstu_clicked();

    void on_btn_addtea_clicked();

    void on_btn_addcourse_clicked();

    void on_btn_del_clicked();

    void on_btn_cancel_clicked();

    void on_btn_return_clicked();

private:
    Ui::system *ui;
};

#endif // SYSTEM_H
