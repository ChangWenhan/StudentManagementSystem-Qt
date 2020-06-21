#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>

namespace Ui {
class addstudent;
}

class addstudent : public QDialog
{
    Q_OBJECT

public:
    explicit addstudent(QWidget *parent = nullptr);
    ~addstudent();

private slots:
    void on_addButton_clicked();

    void on_returnbutton_clicked();

    void writeToFile(QString cnt);

    void clearUserInterface();

private:
    Ui::addstudent *ui;
    QList<QString> adds_lines;
};

#endif // ADDSTUDENT_H
