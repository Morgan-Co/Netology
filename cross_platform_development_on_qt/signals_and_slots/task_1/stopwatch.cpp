#include "stopwatch.h"
#include <QDebug>

Stopwatch::Stopwatch(QObject *parent)
    : QObject(parent) {

    connect(&timer, &QTimer::timeout, this, &Stopwatch::elapsedTime);
    timer.setInterval(100);
}

void Stopwatch::start() {
    if (!elapsedTimer.isValid()) {
        elapsedTimer.start();
    } else {
        elapsedTimer.restart();
    }
    running = true;
    timer.start();
}

void Stopwatch::stop() {
    if (elapsedTimer.isValid()) {
        timer.stop();
        storedTime += elapsedTimer.elapsed();
    }
    running = false;
}

void Stopwatch::reset() {
    if (elapsedTimer.isValid()) {
        elapsedTimer.restart();
        storedTime = 0;
    }
}

Lap Stopwatch::lap() {
    static int lapId = 1;
    qint64 currentTime = storedTime + elapsedTimer.elapsed();
    qint64 lapTime = currentTime - lastLap;
    lastLap = elapsedTimer.elapsed();

    Lap newLap{ currentTime, lapTime, lapId };
    lapId++;

    return newLap;
}

void Stopwatch::elapsedTime() {
    qint64 time = storedTime + elapsedTimer.elapsed();
    int seconds = time / 1000;
    int ms = (time / 100) % 10;

    QString formatedTime = QString("%1.%2")
                               .arg(seconds, 2, 10, QChar('0'))
                               .arg(ms, 2, 10, QChar('0'));


    emit timeUpdated(formatedTime);
}

bool Stopwatch::isRunning() {
    return running;
}








