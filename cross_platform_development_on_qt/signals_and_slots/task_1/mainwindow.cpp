#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFont font = ui->timer_value->font();
    font.setPointSize(26);

    connect(&stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateDisplay);
    connect(&stopwatch, &Stopwatch::requestTime, this, &MainWindow::getTimeText);
    connect(ui->start_button, &QPushButton::clicked, &stopwatch, &Stopwatch::startStop);
    connect(ui->round_button, &QPushButton::clicked, &stopwatch, &Stopwatch::round);
}

MainWindow::~MainWindow()
{
    delete ui;
}



// void MainWindow::on_reset_button_clicked() {
//     timer->stop();
//     milliseconds = 0;

//     ui->timer_value->setText("00:00");
//     ui->start_button->setText("Start");
// }

void MainWindow::updateDisplay(QString timeText) {
    ui->timer_value->setText(timeText);
}

QString MainWindow::getTimeText() {
    return ui->timer_value->text();
}
