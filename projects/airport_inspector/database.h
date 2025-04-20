#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QObject>
#include <QDateTime>

struct FlightInfo {
    QString flightNo;
    QDateTime time;
    QString otherAirportName;
};


class DataBase : public QObject
{
    Q_OBJECT
public:
    DataBase(QObject *parent = nullptr);

signals:
    void sig_sendAirportsToGui(const QVector<QPair<QString, QString>> &);
    void sig_sendStatusConnection(bool status);
    void sig_sendFlightsToGui(const QVector<FlightInfo> &);
    void sig_displayYearStat(const QVector<QPair<QDate, int>> &);
    void sig_displayMonthStat(const QVector<QPair<QDate, int>> &);

public:
    void loadAirports();
    void requestData(const QDate &date, const QString &airport, const QString &direction);
    void connectToDatabase();
    void requestToYearStat(const QString &);
    void requestToMonthStat(const QString &, const int & month);

private:
    QSqlDatabase database;

};

#endif // DATABASE_H
