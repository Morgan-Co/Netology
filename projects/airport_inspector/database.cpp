#include "database.h"

#include <QSqlError>
#include <QSqlQuery>

DataBase::DataBase(QObject *parent) :
    QObject(parent), database(QSqlDatabase::addDatabase("QPSQL")) {
}

void DataBase::connectToDatabase() {
    database.setHostName("981757-ca08998.tmweb.ru");
    database.setPort(5432);
    database.setDatabaseName("demo");
    database.setUserName("netology_usr_cpp");
    database.setPassword("CppNeto3");

    bool status = database.open();

    emit sig_sendStatusConnection(status);
}


void DataBase::loadAirports() {
    QSqlQuery query(database);
    QVector<QPair<QString, QString>> airports;
    if (query.exec("SELECT airport_name->>'ru' as \"airportName\", airport_code FROM bookings.airports_data")) {
        while (query.next()) {

            QString airportName = query.value("airportName").toString();
            QString airportCode = query.value("airport_code").toString();
            airports.append({airportName, airportCode});
        }
    }

    emit sig_sendAirportsToGui(airports);
}

void DataBase::requestData(const QDate &date, const QString &airport, const QString &direction) {
    QSqlQuery query(database);
    QString queryStr;
    if (direction == "arrival") {
        queryStr = R"(SELECT flight_no, scheduled_arrival, ad.airport_name->>'ru' as "Name" from bookings.flights f
                        JOIN bookings.airports_data ad on ad.airport_code = f.departure_airport
              where f.arrival_airport  = :airportCode AND DATE(scheduled_arrival) = :selectedDate)";
    } else {
        queryStr = R"(SELECT flight_no, scheduled_departure, ad.airport_name->>'ru' as "Name"                                              from bookings.flights f
                   JOIN bookings.airports_data ad on ad.airport_code = f.arrival_airport
                  WHERE f.departure_airport  = :airportCode AND DATE(scheduled_departure) = :selectedDate)";
    }

    query.prepare(queryStr);
    query.bindValue(":airportCode", airport);
    query.bindValue(":selectedDate", date);

    QVector<FlightInfo> flights;
    if (query.exec()) {
        QString timeField = (direction == "arrival") ? "scheduled_arrival" : "scheduled_departure";
        while (query.next()) {
            QString flightNo = query.value("flight_no").toString();
            QDateTime arrivalTime = query.value(timeField).toDateTime();
            QString airportName = query.value("Name").toString();
            flights.append({flightNo, arrivalTime, airportName});
        }
    } else {
        qDebug() << "Ошибка запроса:" << query.lastError().text();
    }
    emit sig_sendFlightsToGui(flights);

}

void DataBase::requestToYearStat(const QString &airportCode) {
    QString strQuery = R"(SELECT count(flight_no), date_trunc('month', scheduled_departure) as "Month" from bookings.flights f
                                                             WHERE (scheduled_departure::date > date('2016-08-31') and scheduled_departure::date <= date('2017-08-31')) and ( departure_airport = :airportCode or arrival_airport = :airportCode )
                                                         group by "Month")";

    QSqlQuery query;
    query.prepare(strQuery);
    query.bindValue(":airportCode", airportCode);

    QVector<QPair<QDate, int>> flightStats;
    if (query.exec()) {
        while(query.next()) {
            int count = query.value(0).toInt();
            QDate month = query.value("Month").toDate();
            flightStats.append({month, count});
        }
    }
    emit sig_displayYearStat(flightStats);
}

void DataBase::requestToMonthStat(const QString &airportCode, const int &month) {
    QString strQuery = R"(
    SELECT count(flight_no), date_trunc('day', scheduled_departure) AS "Day"
    FROM bookings.flights f
    WHERE scheduled_departure::date >= DATE('2016-09-01')
      AND scheduled_departure::date <= DATE('2017-08-31')
      AND EXTRACT(MONTH FROM scheduled_departure) = :month
      AND (departure_airport = :airportCode OR arrival_airport = :airportCode)
    GROUP BY "Day"
    ORDER BY "Day"
)";
    QSqlQuery query;
    query.prepare(strQuery);


    query.bindValue(":airportCode", airportCode);
    query.bindValue(":month", month);

    QVector<QPair<QDate, int>> flightStats;
    if (query.exec()) {
        while (query.next()) {
            int count = query.value(0).toInt();
            QDate date = query.value(1).toDate();
            flightStats.append({date, count});
        }
    }
    emit sig_displayMonthStat(flightStats);
}
