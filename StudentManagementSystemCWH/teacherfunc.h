#ifndef TEACHERFUNC_H
#define TEACHERFUNC_H

#include <QDialog>
#include <QStackedLayout>
#include"addstudent.h"
#include"selectstudent.h"
#include"sortstudent.h"
#include"modifystudent.h"

namespace Ui {
class teacherfunc;
}

class teacherfunc : public QDialog
{
    Q_OBJECT

public:
    explicit teacherfunc(QWidget *parent = nullptr);
    ~teacherfunc();

signals:
    void display(int number);

private slots:
    void on_addButton_clicked();

    void on_modifyButton_clicked();

    void on_modifyButton_2_clicked();

    void on_sortButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::teacherfunc *ui;

};

#endif // TEACHERFUNC_H
