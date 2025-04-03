#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTextStream out(stdout);
    ui->password->setEchoMode(QLineEdit::Password);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    std::vector<QString> results;
    QString *hostName = new QString(ui->hostname->text());
    QString *dbName = new QString(ui->database_name->text());
    QString *login = new QString(ui->login->text());
    QString *password = new QString(ui->password->text());
    unsigned int connection_protocol = ui->connection_protocol->text().toUInt();

    results.push_back(ui->hostname->text());
    results.push_back(ui->database_name->text());
    results.push_back(ui->login->text());
    results.push_back(ui->password->text());
    results.push_back(ui->connection_protocol->text());

    qDebug() << "Host name: " << *hostName;
    qDebug() << "Database name: " << *dbName;
    qDebug() << "Login: " << *login;
    qDebug() << "Password: " << *password;
    qDebug() << "Connection protocol: " << connection_protocol;


    Dialog dialog(results, this);
    dialog.exec();

}
