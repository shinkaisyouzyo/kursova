// workermainwindow.h

#ifndef WORKERMAINWINDOW_H
#define WORKERMAINWINDOW_H

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
    explicit workermainwindow(QWidget *parent = nullptr);
    ~workermainwindow();

    static double pributok;

private slots:
    void on_list1_itemClicked(QListWidgetItem *item);
    void on_list2_itemClicked(QListWidgetItem *item);
    void on_pushButton_2_clicked();
    void addItemWithPrice(const QString &itemName);
    void updateTotalPrice();
    void on_pushButton_clicked();


private:
    Ui::workermainwindow *ui;
    QMap<QString, double> prices;
    QString selectedProductName;
    QVector<double> selectedPrices;
    druk *window1;

private:
    QStringList selectedItemsNames;

};

#endif
