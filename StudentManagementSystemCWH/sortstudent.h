#ifndef SORTSTUDENT_H
#define SORTSTUDENT_H
#include<QDialog>
#include<QStandardItem>
#include<QStandardItemModel>
#include<QDebug>

namespace Ui {
class Sortstudent;
}

class Sortstudent : public QDialog
{
    Q_OBJECT

public:
    explicit Sortstudent(QWidget *parent = nullptr);
    ~Sortstudent();

private slots:
    int readfile();

    void on_btn_dosort_clicked();

    void on_btn_analyse_clicked();

private:
    Ui::Sortstudent *ui;
    QStandardItemModel *model;
    QList<QString> score_line;
};

#endif // SORTSTUDENT_H
