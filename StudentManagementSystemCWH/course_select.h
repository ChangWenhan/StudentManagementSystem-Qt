#ifndef COURSE_SELECT_H
#define COURSE_SELECT_H

#include <QDialog>
#include<QStandardItem>
#include<QStandardItemModel>

namespace Ui {
class course_select;
}

class course_select : public QDialog
{
    Q_OBJECT

public:
    explicit course_select(QWidget *parent = nullptr);
    ~course_select();
    int readfile();
    void display(int row,QStringList score_line);
    void initialization();
private slots:
    void on_button_find_clicked();
    
    void on_button_select_clicked();
    
private:
    Ui::course_select *ui;
    QStandardItemModel *model;
    QList<QString> course_line;
    int row[20]={0};
};

#endif // COURSE_SELECT_H
