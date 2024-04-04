#ifndef WORKERWINDOW_H
#define WORKERWINDOW_H

#include <QDialog>
#include "workermainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class workerwindow; }
QT_END_NAMESPACE

class MainWindow;

class workerwindow : public QDialog
{
    Q_OBJECT

signals:
    void closed();

public:
    explicit workerwindow(QWidget *parent = nullptr);
    ~workerwindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::workerwindow *ui;
    MainWindow *mainWindow;
    workermainwindow *window1;
};

#endif // WORKERWINDOW_H
