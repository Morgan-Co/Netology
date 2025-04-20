#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "stats.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_request_clicked();
    void on_pb_stats_clicked();
    void DisplayAirportNames(const QVector<QPair<QString, QString>> &);
    void ReceiveStatusConnection(bool status);
    void DisplayFlights(const QVector<FlightInfo> &);
    void tryReconnect();

private:
    void initUi();
    void connectSignals();
    Ui::MainWindow *ui;
    DataBase database;
    QTimer *reconnectTimer;
    Stats *stats;

    void setInterfaceEnabled(bool enabled);
};
#endif // MAINWINDOW_H
