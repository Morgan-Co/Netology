#include "stopwatch.h"
#include <QPair>
#include <QDebug>

Stopwatch::Stopwatch(QObject *parent)
    : QObject(parent),
    milliseconds(0),
    round_count(0)
{
    timer.setInterval(100);

    connect(&timer, &QTimer::timeout, this, &Stopwatch::updateTime);
}

void Stopwatch::startStop() {
    if (timer.isActive()) {
        timer.stop();
    } else {
        timer.start();
    }
}


void Stopwatch::updateTime() {
    milliseconds++;

    int seconds = milliseconds / 10;
    int ms = milliseconds % 10;

    QString timeText = QString::asprintf("%02d:%02d", seconds, ms);
    emit timeUpdated(timeText);
}

void Stopwatch::reset() {

}

void Stopwatch::round() {
    round_count++;
    QString *timeText = new QString();
    emit requestTime(*timeText);


    QPair<int, QString> new_round = std::make_pair(round_count, *timeText);

    qDebug() << new_round.first << new_round.second;
}
