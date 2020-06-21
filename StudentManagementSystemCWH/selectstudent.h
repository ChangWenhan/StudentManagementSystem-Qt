#ifndef SELECTSTUDENT_H
#define SELECTSTUDENT_H
#include <QWidget>
#include <QtDebug>
#include <QFile>
#include <QVector>
#include <QMessageBox>
#include <QDialog>
#include <QList>
#include<QString>
#include<QStandardItem>
#include<QStandardItemModel>

namespace Ui {
class Selectstudent;
}

class Selectstudent : public QDialog
{
    Q_OBJECT

public:
    explicit Selectstudent(QWidget *parent = nullptr);
    ~Selectstudent();
    int readFromFile();
    void doQuert(int index,QString cnt);
    void disPlay(int row,QStringList subs);


private slots:


    void on_returnbutton_clicked();


    void on_selectbutton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Selectstudent *ui;
    QList<QString> stu_lines;
    QStandardItemModel*model;
};

#endif // SELECTSTUDENT_H
