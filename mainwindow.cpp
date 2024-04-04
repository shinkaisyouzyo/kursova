#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    ui->groupBox->raise();
    ui->pushButton->raise();


    close();
    window1 = new workerwindow(this);
    window1->show();
}

void MainWindow::on_pushButton_2_clicked()
{

    ui->groupBox_2->raise();
    ui->pushButton_2->raise();


    close();
    window2 = new adminwindow(this);
    window2->show();
}






