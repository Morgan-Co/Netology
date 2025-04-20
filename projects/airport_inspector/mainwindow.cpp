#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    reconnectTimer(new QTimer(this))
{
    ui->setupUi(this);
    initUi();
    connectSignals();

    setInterfaceEnabled(false);
    database.connectToDatabase();
}

void MainWindow::initUi() {
    ui->de_date->setDisplayFormat("dd.MM.yyyy");
    ui->de_date->setMinimumDate(QDate(2016, 8, 31));
    ui->de_date->setMaximumDate(QDate(2017, 8, 31));
    ui->rb_arrival->setChecked(true);
}

void MainWindow::connectSignals() {
    connect(&database, &DataBase::sig_sendStatusConnection, this, &MainWindow::ReceiveStatusConnection);
    connect(&database, &DataBase::sig_sendAirportsToGui, this, &MainWindow::DisplayAirportNames);
    connect(&database, &DataBase::sig_sendFlightsToGui, this, &MainWindow::DisplayFlights);
    connect(reconnectTimer, &QTimer::timeout, this, &MainWindow::tryReconnect);
}

void MainWindow::on_pb_request_clicked() {
    QDate date = ui->de_date->date();
    QString airport = ui->cb_airportNames->currentData().toString();
    QString direction;

    if (ui->rb_arrival->isChecked()) {
        direction = "arrival";
    } else if (ui->rb_departure->isChecked()) {
        direction = "departure";
    }
    database.requestData(date, airport, direction);
}

void MainWindow::DisplayAirportNames(const QVector<QPair<QString, QString>> &airports) {
    ui->cb_airportNames->clear();
    for (const auto &[name, code] : airports) {
        ui->cb_airportNames->addItem(name, code);
    }
}

void MainWindow::ReceiveStatusConnection(bool status) {
    if (status) {
        reconnectTimer->stop();
        setInterfaceEnabled(true);
        database.loadAirports();
        ui->w_status->setStyleSheet("background-color: #57e83a");
    } else {
        ui->w_status->setStyleSheet("background-color: #e83a43");
        setInterfaceEnabled(false);
        QMessageBox::critical(this, "Ошибка подключения",
                              "Не удалось подключиться к базе данных.\nПопробуем снова через 5 секунд.");
        reconnectTimer->start(5000);
    }
}

void MainWindow::DisplayFlights(const QVector<FlightInfo> &flights) {
    ui->tb_flights->clearContents();
    ui->tb_flights->setRowCount(flights.size());
    ui->tb_flights->setColumnCount(3);
    ui->tb_flights->setHorizontalHeaderLabels(QStringList() << "Номер рейса" << "Время" << "Аэропорт");

    for (int i = 0; i < flights.size(); ++i) {
        const auto &f = flights[i];
        ui->tb_flights->setItem(i, 0, new QTableWidgetItem(f.flightNo));
        ui->tb_flights->setItem(i, 1, new QTableWidgetItem(f.time.toString("dd.MM.yyyy HH:mm")));
        ui->tb_flights->setItem(i, 2, new QTableWidgetItem(f.otherAirportName));
    }
    ui->tb_flights->setColumnWidth(1, 200);
    ui->tb_flights->setColumnWidth(2, 200);
};

void MainWindow::on_pb_stats_clicked() {
    QString code = ui->cb_airportNames->currentData().toString();
    QString name = ui->cb_airportNames->currentText();

    QPair<QString, QString> airport{code, name};

    stats = new Stats(airport, &database, this);
    stats->exec();
}

void MainWindow::tryReconnect() {
    database.connectToDatabase();
}

void MainWindow::setInterfaceEnabled(bool enabled) {
    ui->pb_request->setEnabled(enabled);
    ui->de_date->setEnabled(enabled);
    ui->pb_stats->setEnabled(enabled);
    ui->cb_airportNames->setEnabled(enabled);
}

MainWindow::~MainWindow()
{
    delete ui;
}


