#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

extern QString account;
extern QString password;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int readstudentfile();
    int readteacherfile();
    int readcontroller();
    ~MainWindow();

private slots:
    void on_btn_denglu_clicked();

    void on_btn_tuichu_clicked();

private:
    Ui::MainWindow *ui;
    QList<QString> student_line;
    QList<QString> teacher_line;
    QList<QString> controller_line;
};

#endif // MAINWINDOW_H
