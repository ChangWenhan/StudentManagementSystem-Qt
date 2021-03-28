#ifndef CHANGEDATA_H
#define CHANGEDATA_H

#include <QDialog>

namespace Ui {
class changedata;
}

class changedata : public QDialog
{
    Q_OBJECT

public:
    explicit changedata(QWidget *parent = nullptr);
    void writeIn(QString information);
    int readfile();
    ~changedata();

private slots:
    void on_pushButton_clicked(); 

    void on_btn_changedata_change_clicked();

    void on_btn_changedata_del_clicked();

    void on_btn_changedata_cancel_clicked();

private:
    Ui::changedata *ui;
    QList<QString> score_line;
};

#endif // CHANGEDATA_H
