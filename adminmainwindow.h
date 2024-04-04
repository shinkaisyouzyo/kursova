#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class adminmainwindow;
}

class adminmainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminmainwindow(QWidget *parent = nullptr);
    ~adminmainwindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminmainwindow *ui;
    QSqlDatabase db;
};

#endif
