#include "addworker.h"
#include "ui_addworker.h"
#include <QtSql>
#include "QMessageBox"
#include "adminmainwindow.h"

addworker::addworker(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addworker)
{
    ui->setupUi(this);

    aw = new adminmainwindow();

    connect(ui->pushButton, &QPushButton::clicked, this, &addworker::addNewWorker);
}

addworker::~addworker()
{
    delete ui;
}

void addworker::addNewWorker() {

    if (ui->lineEdit->text().isEmpty() ||
        ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty() ||
        ui->lineEdit_4->text().isEmpty() ||
        ui->lineEdit_5->text().isEmpty() ||
        ui->lineEdit_6->text().isEmpty() ||
        ui->lineEdit_7->text().isEmpty()) {
        QMessageBox::critical(this, "Error", "Будь ласка, заповніть всі поля!");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO employees (full_name, position, salary, characteristics, monthly_profit, working_days, missed_days) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(ui->lineEdit->text());
    query.addBindValue(ui->lineEdit_2->text());
    query.addBindValue(ui->lineEdit_3->text().toDouble());
    query.addBindValue(ui->lineEdit_4->text());
    query.addBindValue(ui->lineEdit_5->text().toDouble());
    query.addBindValue(ui->lineEdit_6->text().toInt());
    query.addBindValue(ui->lineEdit_7->text().toInt());

    if(query.exec()) {
        QMessageBox::information(this, "Success", "Нового робітника додано!");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
    } else {
        QMessageBox::critical(this, "Error", "Сталася помилка!");
    }
}


void addworker::on_pushButton_2_clicked()
{
    close();
    aw->show();
}

