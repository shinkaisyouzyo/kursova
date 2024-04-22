#ifndef ADDWORKER_H
#define ADDWORKER_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class adminmainwindow; }
QT_END_NAMESPACE

class adminmainwindow;

namespace Ui {
class addworker;
}

class addworker : public QDialog
{
    Q_OBJECT

public:
    explicit addworker(QWidget *parent = nullptr);
    ~addworker();

    void addNewWorker();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::addworker *ui;
    adminmainwindow *aw;
};

#endif
