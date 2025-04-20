#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include "database.h"


namespace Ui {
class Stats;
}

class Stats : public QDialog
{
    Q_OBJECT

public:
    explicit Stats(const QPair<QString, QString> &, DataBase*, QWidget *parent = nullptr);
    ~Stats();

    void DisplayYearStat(const QVector<QPair<QDate, int>> &);
    void DisplayMonthStat(const QVector<QPair<QDate, int>> &);
private slots:
    void on_pb_close_clicked();

private:
    Ui::Stats *ui;
    DataBase* database;
    QPair<QString, QString> m_airport;
};

#endif // STATS_H
