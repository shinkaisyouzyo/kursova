#include "workerwindow.h"
#include "ui_workerwindow.h"
#include <QMessageBox>
#include "workermainwindow.h"
#include "mainwindow.h" // Включаємо файл заголовка головного вікна

workerwindow::workerwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::workerwindow)
{
    ui->setupUi(this);

    // Створити екземпляр головного вікна
    mainWindow = new MainWindow();

}

workerwindow::~workerwindow()
{
    delete ui;
}

void workerwindow::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();

    if(login == "User" && password == "123") {
        close();
        window1 = new workermainwindow(this);
        window1->show();
    } else {
        QMessageBox::warning(this, "Авторизація", "Данні введені неправильно");
    }
}

void workerwindow::on_pushButton_2_clicked()
{
    close();
    mainWindow->show(); // Показати існуючий екземпляр головного вікна
}
