#include "workerwindow.h"
#include "ui_workerwindow.h"
#include <QMessageBox>
#include "workermainwindow.h"
#include "mainwindow.h"
#include <QtSql>

workerwindow::workerwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::workerwindow)
{
    ui->setupUi(this);


    mainWindow = new MainWindow();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("employees.db"); // Путь к вашей базе данных SQLite
    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть базу данных!");
    }

}

workerwindow::~workerwindow()
{
    delete ui;
}

void workerwindow::on_pushButton_clicked()
{
    QString login = ui->loginui->text();
    QString password = ui->passwordui->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM employees WHERE login = :login AND password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    if (query.exec() && query.next()) {
        close();
        window1 = new workermainwindow(login, password, this);
        window1->show();
    } else {
        QMessageBox::warning(this, "Авторизация", "Данные введены неправильно");
    }
}


void workerwindow::on_pushButton_2_clicked()
{
    close();
    mainWindow->show();
}
