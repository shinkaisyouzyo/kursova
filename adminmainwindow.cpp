#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"
#include <QtSql>
#include <QDebug>
#include "addworker.h"
#include "QMessageBox"

adminmainwindow::adminmainwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminmainwindow)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("employees.db");


    if (!db.open()) {
        qDebug() << "Помилка при відкритті бази даних:" << db.lastError().text();
        return;
    }

    // Створення таблиці, якщо вона не існує
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS employees ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "full_name TEXT,"
                              "position TEXT,"
                              "salary REAL,"
                              "characteristics TEXT,"
                              "monthly_profit REAL,"
                              "working_days INTEGER,"
                              "missed_days INTEGER"
                              ")");
    if (!success) {
        qDebug() << "Помилка при створенні таблиці:" << query.lastError().text();
        return;
    }


    success = query.exec("INSERT INTO employees (full_name, position, salary, characteristics, monthly_profit, working_days, missed_days) "
                         "VALUES ('Іван Петров', 'Програміст', 5000.0, 'Досвідчений розробник', 10000.0, 20, 2)");

    if (!success) {
        qDebug() << "Помилка додавання даних:" << query.lastError().text();
        return;
    }



}

adminmainwindow::~adminmainwindow()
{
    delete ui;
}

void adminmainwindow::on_pushButton_clicked()
{
    hide();
    addworker window4;
    window4.exec();
}


void adminmainwindow::on_pushButton_2_clicked()
{
    QString employeeName = ui->lineEdit_8->text();


    QSqlQuery selectQuery;
    selectQuery.prepare("SELECT * FROM employees WHERE full_name = ?");
    selectQuery.addBindValue(employeeName);
    if (selectQuery.exec() && selectQuery.next()) {

        QString fullName = selectQuery.value("full_name").toString();
        QString position = selectQuery.value("position").toString();
        double salary = selectQuery.value("salary").toDouble();
        QString characteristics = selectQuery.value("characteristics").toString();
        double monthlyProfit = selectQuery.value("monthly_profit").toDouble();
        int workingDays = selectQuery.value("working_days").toInt();
        int missedDays = selectQuery.value("missed_days").toInt();


        ui->lineEdit->setText(fullName);
        ui->lineEdit_2->setText(position);
        ui->lineEdit_3->setText(QString::number(salary));
        ui->lineEdit_4->setText(characteristics);
        ui->lineEdit_5->setText(QString::number(monthlyProfit));
        ui->lineEdit_6->setText(QString::number(workingDays));
        ui->lineEdit_7->setText(QString::number(missedDays));
    } else {
        QMessageBox::critical(this, "Error", "Працівника з таким ім'ям не знайдено!");
        qDebug() << "Не вдалося отримати дані про працівника з бази даних";
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
    }
}
