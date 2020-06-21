#ifndef MODIFYSTUDENT_H
#define MODIFYSTUDENT_H

#include <QDialog>

namespace Ui {
class Modifystudent;
}

class Modifystudent : public QDialog
{
    Q_OBJECT

public:
    explicit Modifystudent(QWidget *parent = nullptr);
    void writeIn(QString information);
    int readfile();
    ~Modifystudent();



private slots:
    void on_btn_changedata_del_clicked();

    void on_btn_changedata_change_clicked();

    void on_btn_changedata_cancel_clicked();

private:
    Ui::Modifystudent *ui;
    QList<QString> score_line; //存储学生

};

#endif // MODIFYSTUDENT_H
