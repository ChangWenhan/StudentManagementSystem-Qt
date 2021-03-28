#ifndef TEA_QUERYSTU_H
#define TEA_QUERYSTU_H

#include <QDialog>
#include <QStandardItem>
#include <QStandardItemModel>

extern QString name1;
extern QString id1;
extern QString classname1;
extern QString math1;
extern QString eng1;
extern QString phy1;

namespace Ui {
class tea_querystu;
}

class tea_querystu : public QDialog
{
    Q_OBJECT

public:
    explicit tea_querystu(QWidget *parent = nullptr);
    int readfile();
    void reset();
    void display(int row, QStringList score_line);

    ~tea_querystu();

private slots:
    void on_btn_doquery_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

public:
    Ui::tea_querystu *ui;
    QStandardItemModel *model;
    QList<QString> score_line;
};

#endif // TEA_QUERYSTU_H
