// workermainwindow.cpp
#include <QFile>
#include "workermainwindow.h"
#include "ui_workermainwindow.h"
#include "druk.h"
#include <QTextStream>


double workermainwindow::pributok = 0.0;

workermainwindow::workermainwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::workermainwindow)
{
    ui->setupUi(this);


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

    QFile file("pributok.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString pributokStr = in.readAll();
        workermainwindow::pributok = pributokStr.toDouble();
        file.close();
    }
}



workermainwindow::~workermainwindow()
{
    QFile file("pributok.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << workermainwindow::pributok;
        file.close();
    }

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

        selectedItemsNames.append(itemName);


        ui->lineEdit_5->setText(selectedItemsNames.join("\n"));


        selectedPrices.append(price);


        updateTotalPrice();
    }
}








void workermainwindow::on_pushButton_clicked()
{



    QString textFromLineEdit2 = ui->lineEdit_2->text();


    QString textFromLineEdit4 = ui->lineEdit_4->text();

    QString textFromTextEdit5 = ui->lineEdit_5->toPlainText();



    pributok += textFromLineEdit4.toDouble();


    qDebug() << "pributok: " << pributok;


    QString pributokString = QString::number(pributok);


    ui->lineEdit_3->setText(pributokString);


    window1 = new druk(this);
    //  window1->setLineEditValue(textFromLineEdit);
    window1->setLineEdit2Value(textFromLineEdit2);
    window1->setLineEdit3Value(textFromLineEdit4);
    window1->setLineEdit4Value(textFromTextEdit5);
    window1->show();

    QString currentValue = ui->lineEdit_2->text();

    // Преобразуем строку в число (в данном случае, предполагается, что строка содержит действительное число)
    double currentValueDouble = currentValue.toDouble();

    // Увеличиваем значение на ваше число
    double newValue = currentValueDouble + 1;

    // Преобразуем новое значение обратно в строку
    QString newValueString = QString::number(newValue);

    // Устанавливаем новое значение в lineEdit
    ui->lineEdit_2->setText(newValueString);
}


void workermainwindow::on_pushButton_2_clicked()
{
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

    // Очистка списка выбранных элементов и их цен
    selectedItemsNames.clear();
    selectedPrices.clear();


}

// workermainwindow.cpp

void workermainwindow::addItemWithPrice(const QString &itemName)
{
    double price = prices.value(itemName, 0.0);
    QString itemText = itemName + " - Ціна: " + QString::number(price) + " грн.";
    ui->list2->addItem(itemText);

    qDebug() << "Добавлен элемент в list2: " << itemText;  // Отладочный вывод
}



void workermainwindow::updateTotalPrice()
{
    // Обновление значения lineEdit_4
    double total = 0.0;
    for (double itemPrice : selectedPrices) {
        total += itemPrice;
    }

    // Установим обновленное значение lineEdit_4
    ui->lineEdit_4->setText(QString::number(total));

    // Обновим значение lineEdit_5
    ui->lineEdit_5->setText(selectedItemsNames.join("\n"));
}



