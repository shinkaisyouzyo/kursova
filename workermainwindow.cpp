// workermainwindow.cpp
#include <QFile>
#include "workermainwindow.h"
#include "ui_workermainwindow.h"
#include "druk.h"
#include <QTextStream>
#include <QtSql>
#include <QMessageBox>


double workermainwindow::pributok = 0.0;
int workermainwindow::nomerz = 0;
workermainwindow::workermainwindow(const QString &login, const QString &password, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::workermainwindow)
    , employee(login, password, 0.0)
    , currentLogin(login)
{
    ui->setupUi(this);

    loadMonthlyProfitFromDatabase();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("employees.db"); // Путь к вашей базе данных SQLite
    if (!db.open()) {
        // Обработка ошибки подключения к базе данных
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть базу данных!");
    }

    employee.loadEmployeeData(login);
    employee.loadEmployeeData(password);

    connect(ui->list1, &QListWidget::itemClicked, this, &workermainwindow::on_list1_itemClicked);




    prices["Стейк з лосося"] = 250;
    prices["Каррі з курки та овочів"] = 180;
    prices["Паста карбонара з беконом та пармезаном"] = 200;
    prices["Маракуйя-мохіто"] = 70;
    prices["Фреш із апельсина та моркви"] = 60;
    prices["Кава Латте з карамеллю"] = 50;
    prices["Чізкейк з малиновим соусом"] = 120;
    prices["Тірамісу з кавовими бобами"] = 100;
    prices["Шоколадний фондан з ванільним морозивом"] = 150;
    prices["Курячий сендвіч з авокадо та чіпсами з солі"] = 130;
    prices["Квітковий рол з лососем та тунцем"] = 150;
    prices["Каррі з кінського м'яса з басматі-рисом"] = 180;
    prices["Маргарита з томатами та базиліком"] = 180;
    prices["Піца з куркою, грибами та сиром фета"] = 200;
    prices["Піца зі шпинатом, пармезаном та горішками"] = 220;
    prices["Цезар з куркою та грінками"] = 150;
    prices["Грецький салат з оливками та фето"] = 120;
    prices["Салат з авокадо, креветками та манго"] = 180;

 }



workermainwindow::~workermainwindow()
{

    delete ui;
}

void workermainwindow::on_list1_itemClicked(QListWidgetItem *item)
{

    ui->list2->clear();
    selectedProductName = item->text();

    qDebug() << "Выбран тип товара из list1: " << selectedProductName;


    if (!ui->list2->findItems(selectedProductName, Qt::MatchExactly).isEmpty()) {

        return;
    }


    if (selectedProductName == "Гарячі страви") {
        addItemWithPrice("Стейк з лосося");
        addItemWithPrice("Каррі з курки та овочів");
        addItemWithPrice("Паста карбонара з беконом");
    } else if (selectedProductName == "Напої") {
        addItemWithPrice("Маракуйя-мохіто");
        addItemWithPrice("Фреш із апельсина та моркви");
        addItemWithPrice("Кава Латте з карамеллю");
    }
    else if (selectedProductName == "Десерти") {
        addItemWithPrice("Чізкейк з малиновим соусом");
        addItemWithPrice("Тірамісу з кавовими бобами");
        addItemWithPrice("Шоколадний фондан з ванільним морозивом");
    }
    else if (selectedProductName == "Ланчі") {
        addItemWithPrice("Курячий сендвіч з авокадо та чіпсами з солі");
        addItemWithPrice("Квітковий рол з лососем та тунцем");
        addItemWithPrice("Каррі з кінського м'яса з басматі-рисом");
    }
    else if (selectedProductName == "Піцци") {
        addItemWithPrice("Маргарита з томатами та базиліком");
        addItemWithPrice("Піца з куркою, грибами та сиром фета");
        addItemWithPrice("Піца зі шпинатом, пармезаном та горішками");
    }
    else if (selectedProductName == "Салати") {
        addItemWithPrice("Цезар з куркою та грінками");
        addItemWithPrice("Грецький салат з оливками та фето");
        addItemWithPrice("Салат з авокадо, креветками та манго");
    }

}




void workermainwindow::on_list2_itemClicked(QListWidgetItem *item)
{
    qDebug() << "on_list2_itemClicked called";

    if (item) {
        QString itemName = item->text().split(" - ").first();
        double price = prices.value(itemName, 0.0);

        // Добавляем цену товара к текущей общей стоимости
        double currentMonthlyProfit = ui->lineEdit_3->text().toDouble();
        double total = currentMonthlyProfit + price;

        // Устанавливаем новое значение общей стоимости в lineEdit_3
        ui->lineEdit_3->setText(QString::number(total));
    }
}



void workermainwindow::on_pushButton_clicked()
{



    QString textFromLineEdit2 = ui->lineEdit_2->text();

    QString monthlyProfitString = ui->lineEdit_3->text();
    double monthlyProfit = monthlyProfitString.toDouble();

    QString textFromLineEdit4 = ui->lineEdit_4->text();

    QString textFromTextEdit5 = ui->lineEdit_5->toPlainText();

    QString currentMonthlyProfitString = ui->lineEdit_3->text();
    double currentMonthlyProfit = currentMonthlyProfitString.toDouble();
    double updatedMonthlyProfit = currentMonthlyProfit + pributok;


     ui->lineEdit_3->setText(QString::number(updatedMonthlyProfit));


    QSqlQuery query;
    query.prepare("UPDATE employees SET monthly_profit = :monthlyProfit WHERE login = :login");
    query.bindValue(":monthlyProfit", monthlyProfit);
    query.bindValue(":login", currentLogin);
    if (!query.exec()) {
        // Обработка ошибки
    }


    window1 = new druk(this);
    window1->setLineEdit2Value(textFromLineEdit2);
    window1->setLineEdit3Value(textFromLineEdit4);
    window1->setLineEdit4Value(textFromTextEdit5);
    window1->show();

    QString currentValue = ui->lineEdit_2->text();


    double currentValueDouble = currentValue.toDouble();


    double newValue = currentValueDouble + 1;


    QString newValueString = QString::number(newValue);


    ui->lineEdit_2->setText(newValueString);


    double additionalProfit = ui->lineEdit_4->text().toDouble(); // Получаем дополнительную прибыль
    employee.updateEmployeeProfit(additionalProfit);
}


void workermainwindow::on_pushButton_2_clicked()
{
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();


    selectedItemsNames.clear();
    selectedPrices.clear();


}



void workermainwindow::addItemWithPrice(const QString &itemName)
{
    double price = prices.value(itemName, 0.0);
    QString itemText = itemName + " - Ціна: " + QString::number(price) + " грн.";
    ui->list2->addItem(itemText);

    qDebug() << "Добавлен элемент в list2: " << itemText;
}



void workermainwindow::loadMonthlyProfitFromDatabase()
{
    // Загрузка значения monthly_profit из базы данных для текущего пользователя
    QSqlQuery query;
    query.prepare("SELECT monthly_profit FROM employees WHERE login = :login");
    query.bindValue(":login", currentLogin);
    if (!query.exec() || !query.first()) {
        // Обработка ошибки или пользователя не найден
        return;
    }

    double monthlyProfit = query.value(0).toDouble();
    QString monthlyProfitString = QString::number(monthlyProfit);

    // Установка значения в lineEdit_3
    ui->lineEdit_3->setText(monthlyProfitString);
}


