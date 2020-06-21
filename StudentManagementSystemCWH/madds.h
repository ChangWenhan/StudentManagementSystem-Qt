#ifndef MADDS_H
#define MADDS_H
#include<QMessageBox>
#include <QDialog>
#include<QString>
#include<QList>
#include<QTextStream>

namespace Ui {
class Madds;
}

class Madds : public QDialog
{
    Q_OBJECT

public:
    explicit Madds(QWidget *parent = nullptr);
    ~Madds();

    void clearUserInterface();

    void writeToFile(QString cnt);

    void writeToFile_2(QString cnt);

private slots:
    void on_addbtn_clicked();

    void on_backbtn_clicked();

private:
    Ui::Madds *ui;
    QList<QString> adds_lines;

};

#endif // MADDS_H
