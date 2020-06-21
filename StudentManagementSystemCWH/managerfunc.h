#ifndef MANAGERFUNC_H
#define MANAGERFUNC_H

#include <QDialog>

namespace Ui {
class managerfunc;
}

class managerfunc : public QDialog
{
    Q_OBJECT

public:
    explicit managerfunc(QWidget *parent = nullptr);
    ~managerfunc();

private slots:
    void on_changePeople_clicked();

    void on_pushButton_clicked();

    void on_addmodule_clicked();

    void on_changeClass_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::managerfunc *ui;
};

#endif // MANAGERFUNC_H
