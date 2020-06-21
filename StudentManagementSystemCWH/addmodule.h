#ifndef ADDMODULE_H
#define ADDMODULE_H

#include <QDialog>

namespace Ui {
class addmodule;
}

class addmodule : public QDialog
{
    Q_OBJECT

public:
    explicit addmodule(QWidget *parent = nullptr);
    ~addmodule();

    void clearUserInterface();

    void writeToFile(QString cnt);
private slots:
    void on_Cancelbtn_clicked();

    void on_OKbtn_clicked();

private:
    Ui::addmodule *ui;
};

#endif // ADDMODULE_H
