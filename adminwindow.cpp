#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QMessageBox>
#include "adminmainwindow.h"
#include "mainwindow.h"

adminwindow::adminwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminwindow)
{
    ui->setupUi(this);


    mainWindow = new MainWindow();

}
adminwindow::~adminwindow()
{
    delete ui;
}

void adminwindow::on_pushButton_clicked()
{
    QString login = ui->login1->text();
    QString password = ui->password1->text();

    if(login == "Admin" && password == "123") {
        close();
        adminmainwindow window3;
        window3.exec();
    } else{
        QMessageBox::warning(this, "Авторизація", "Данні введені неправильно");
    }
}

void adminwindow::on_pushButton_2_clicked()
{
    close();
    mainWindow->show();
}
