#ifndef DRUK_H
#define DRUK_H

#include <QDialog>

namespace Ui {
class druk;
}

class druk : public QDialog
{
    Q_OBJECT

public:
    void setLineEditValue(const QString &value);
    void setLineEdit2Value(const QString &value);
    void setLineEdit3Value(const QString &value);
    void setLineEdit4Value(const QString &value);
    explicit druk(QWidget *parent = nullptr);
    ~druk();

private slots:
    void on_pushButton_clicked();

private:
    Ui::druk *ui;
};

#endif
