#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "about.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QStringList>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Exit_clicked()
{
    this->close();
}

void MainWindow::on_Stubtn_clicked()
{
    this->hide();
    cwhmenu.exec();
}

void MainWindow::on_Teabtn_clicked()
{
    this->hide();
    cwhteachermenu.exec();
}

void MainWindow::on_Manbtn_clicked()
{
    this->hide();
    cwhmanagemermenu.exec();
}
