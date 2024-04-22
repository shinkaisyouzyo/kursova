#include "employee.h"
#include <QtSql>

Employee::Employee(const QString &login, const QString &password, double monthlyProfit) :
    login(login),
    password(password),
    monthlyProfit(monthlyProfit) {
    // Инициализация, если необходимо
}

void Employee::loadEmployeeData(const QString &login) {
    QSqlQuery query;
    query.prepare("SELECT * FROM employees WHERE login = :login");
    query.bindValue(":login", login);
    if (query.exec() && query.next()) {

      //  login = query.value("login").toString();
        password = query.value("password").toString();
        monthlyProfit = query.value("monthly_profit").toDouble();
    }
}

// В методе updateEmployeeProfit класса Employee
void Employee::updateEmployeeProfit(double additionalProfit) {
    monthlyProfit += additionalProfit;

    QSqlQuery query;
    query.prepare("UPDATE employees SET monthly_profit = :monthly_profit WHERE login = :login");
    query.bindValue(":monthly_profit", monthlyProfit);
    query.bindValue(":login", login);
    query.exec();
}
