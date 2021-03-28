#ifndef TEA_SCOREIMPORT_H
#define TEA_SCOREIMPORT_H

#include <QDialog>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class tea_scoreimport;
}

class tea_scoreimport : public QDialog
{
    Q_OBJECT

public:
    explicit tea_scoreimport(QWidget *parent = nullptr);
    void display(int row,QStringList subs);
    ~tea_scoreimport();

private slots:
    void reset();

    int readfile();

    void on_btn_dosort_clicked();

    void on_btn_analyse_clicked();

private:
    Ui::tea_scoreimport *ui;
    QStandardItemModel *model;
    QList<QString> score_line;
};

#endif // TEA_SCOREIMPORT_H
