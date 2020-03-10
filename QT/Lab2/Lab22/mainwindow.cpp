#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    exit(1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_6->hide();
    QString secondName = "Шепетуха";
    QString firsName ="Сергей";
    QString otchestvo = "Игоревич";
    QString birthday = "05.02.1998";
    QDate Mydate= ui->dateEdit->date();
    QString birthdayUI = Mydate.toString();
    if(QString::compare(ui->lineEdit->placeholderText(),otchestvo) && QString::compare (ui->lineEdit_2->placeholderText(),firsName ) &&  QString::compare(ui->lineEdit_3->placeholderText(),secondName) && QString::compare(birthdayUI,birthday) )
    {
        ui->label_6->setText("Данные совпали!");
        ui->label_6->show();
    }

}
