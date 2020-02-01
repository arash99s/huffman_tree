#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QProcess"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon compress_icon("/home/arash/QtProjects/WIN/download.png");
    ui->pushButton->setIcon(compress_icon);
    QIcon extract_icon("/home/arash/QtProjects/WIN/extract.png");
    ui->pushButton_2->setIcon(extract_icon);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString input = start;
    input += " 1 ";
    input += ui->textEdit->toPlainText();
    QProcess::execute (input);
    QMessageBox::about(this , "", "your file successfully compressed");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString input = start;
    input += " 2 ";
    input += ui->textEdit->toPlainText();
    QProcess::execute (input);
    QMessageBox::about(this , "", "your file successfully extracted");
}
