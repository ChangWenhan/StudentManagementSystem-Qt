#ifndef MANAGERMENU_H
#define MANAGERMENU_H
#include"managerfunc.h"
#include <QDialog>

namespace Ui {
class Managermenu;
}

class Managermenu : public QDialog
{
    Q_OBJECT

public:
    explicit Managermenu(QWidget *parent = nullptr);
    ~Managermenu();
    int readFromFile();
    QString account;
    QString password;

private slots:
    void on_pushButton_2_clicked();

    void on_Loginbtn_clicked();

private:
    Ui::Managermenu *ui;
    QList<QString> man_lines;
    managerfunc cwhmanagerfunc;
};

#endif // MANAGERMENU_H
