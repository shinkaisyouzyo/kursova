#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

class Employee {
public:
    QString login;
    QString password;
    double monthlyProfit;

    // Конструктор
    Employee(const QString &login, const QString &password, double monthlyProfit);

    // Функция для загрузки данных о работнике из базы данных
    void loadEmployeeData(const QString &login);

    // Функция для обновления заработной платы работника
    void updateEmployeeProfit(double additionalProfit);
};

#endif // EMPLOYEE_H
