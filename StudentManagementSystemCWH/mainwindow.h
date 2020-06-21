#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include "teachermenu.h"
#include "managermenu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //int readfile_student();

private slots:
    void on_Exit_clicked();

    void on_Stubtn_clicked();

    void on_Teabtn_clicked();

    void on_Manbtn_clicked();

private:
    Ui::MainWindow *ui;
    Menu cwhmenu;
    Teachermenu cwhteachermenu;
    Managermenu cwhmanagemermenu;
    //QList<QString> student_line;
};

#endif // MAINWINDOW_H
