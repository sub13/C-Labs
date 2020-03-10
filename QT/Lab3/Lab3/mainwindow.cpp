#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>


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

static QString fileName;
void MainWindow::on_action_3_triggered() //action OPEN
{
    fileName = QFileDialog::getOpenFileName( this, "Открыть файл...", QDir::homePath(), "Text files (*.txt);;All files (*.*)" );
    if (fileName.isEmpty())
        return;
    QFile fileText(fileName);
    if(fileText.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream reader(&fileText);
        QString data;
        data = reader.readAll();
        ui->plainTextEdit->setPlainText(data);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", QString("Невозможно открыть файл").arg(fileName), QMessageBox::Ok);
        return;
    }
    fileText.flush();
    fileText.close();
}

void MainWindow::on_action_triggered()
{
    fileName = QFileDialog::getSaveFileName( this, "Сохранить файл...", QDir::homePath(), "Text files (*.txt);;All files (*.*)" );
    if (fileName.isEmpty())
        return;
    QFile fileText(fileName);
    if(fileText.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream writer(&fileText);
        QString data = ui->plainTextEdit->toPlainText();
        writer << data;
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", QString("Невозможно сохранить файл").arg(fileName), QMessageBox::Ok);
        return;
    }
    fileText.flush();
    fileText.close();
}

void MainWindow::on_action_2_triggered()
{
    QFile fileText(fileName);
    if (fileName.isEmpty() || !fileText.open(QFile::ReadOnly | QFile::Text))
    {
        fileText.flush();
        fileText.close();
        MainWindow::on_action_triggered();
        return;
    }
    fileText.flush();
    fileText.close();
    if(fileText.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream writer(&fileText);
        QString data = ui->plainTextEdit->toPlainText();
        writer << data;
    }
    else
    {
        QMessageBox::warning(this, fileName, QString("Невозможно сохранить файл").arg(fileName), QMessageBox::Ok);
        return;
    }
    fileText.flush();
    fileText.close();
}
