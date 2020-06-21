#ifndef TEACHERMENU_H
#define TEACHERMENU_H
#include"teacherfunc.h"

#include <QDialog>

namespace Ui {
class Teachermenu;
}

class Teachermenu : public QDialog
{
    Q_OBJECT

public:
    explicit Teachermenu(QWidget *parent = nullptr);
    ~Teachermenu();
    int readFromFile();
    QString account;
    QString password;

private slots:
    void on_pushButton_2_clicked();

    void on_Loginbtn_clicked();

private:
    Ui::Teachermenu *ui;
    QList<QString> tea_lines;
    teacherfunc tfunc;
};

#endif // TEACHERMENU_H
