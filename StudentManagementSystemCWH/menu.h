#ifndef MENU_H
#define MENU_H
#include <QDialog>
#include <QFile>
#include <QList>
#include <QString>
#include"studentfunc.h"


namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    int readFromFile();
    QString account;
    QString password;

private slots:
    void on_pushButton_2_clicked();

    void on_Loginbtn_clicked();

private:
    Ui::Menu *ui;
    QList<QString> stu_lines;
    StudentFunc cwhstudentfunc;

};

#endif // MENU_H
