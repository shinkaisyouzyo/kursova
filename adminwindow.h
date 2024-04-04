#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class adminwindow; }
QT_END_NAMESPACE

class MainWindow;

class adminwindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminwindow(QWidget *parent = nullptr);
    ~adminwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminwindow *ui;
    MainWindow *mainWindow;
};

#endif
