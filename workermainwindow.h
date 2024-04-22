// workermainwindow.h

#ifndef WORKERMAINWINDOW_H
#define WORKERMAINWINDOW_H
#include "employee.h"

#include <QDialog>
#include <QListWidgetItem>
#include <QMap>
#include "druk.h"

namespace Ui {
class workermainwindow;
}

class workermainwindow : public QDialog
{
    Q_OBJECT

public:
    workermainwindow(const QString &login, const QString &password, QWidget *parent = nullptr);
    ~workermainwindow();

    static double pributok;
    static int nomerz;

private slots:
    void on_list1_itemClicked(QListWidgetItem *item);
    void on_list2_itemClicked(QListWidgetItem *item);
    void on_pushButton_2_clicked();
    void addItemWithPrice(const QString &itemName);
    void updateTotalPrice();
    void on_pushButton_clicked();
    void loadMonthlyProfitFromDatabase();


private:
    Ui::workermainwindow *ui;
    QMap<QString, double> prices;
    QString selectedProductName;
    QVector<double> selectedPrices;
    druk *window1;
    Employee employee;
    QString currentLogin;

private:
    QStringList selectedItemsNames;

};

#endif
