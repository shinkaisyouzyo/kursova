#include "druk.h"
#include "ui_druk.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>



druk::druk(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::druk)
{
    ui->setupUi(this);
}

druk::~druk()
{
    delete ui;
}

void druk::setLineEdit2Value(const QString &value)
{
    ui->lineEdit_2->setText(value);
}

void druk::setLineEdit3Value(const QString &value)
{
    ui->lineEdit_3->setText(value);
}
void druk::setLineEdit4Value(const QString &value)
{
    ui->lineEdit_4->setText(value);
}
void druk::on_pushButton_clicked()
{

    QPrinter printer;


    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() != QDialog::Accepted)
        return;


    QPainter painter(&printer);

    QString lineEditText = ui->lineEdit_4->toPlainText();


    QStringList lines = lineEditText.split("\n");


    int yPos = 100;


    painter.drawText(100, yPos, "номер замовлення:");
    yPos += 20;


    painter.drawText(100, yPos, ui->lineEdit_2->text());
    yPos += 20;


    painter.drawText(100, yPos, "ціна:");
    yPos += 20;


    painter.drawText(100, yPos, ui->lineEdit_3->text());
    yPos += 20;


    for(const QString &line : lines) {
        painter.drawText(100, yPos, line);
        yPos += 20;
    }
}

