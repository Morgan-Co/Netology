#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtSql/QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Экземпляр для работы с сетью
    QNetworkAccessManager networkManager;
    qDebug() << "QNetworkAccessManager создан.";

    // Экземпляр для работы с базой данных (SQLite)
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (db.open()) {
        qDebug() << "База данных успешно открыта.";
    } else {
        qDebug() << "Ошибка открытия базы данных";
    }

    return a.exec();
}
