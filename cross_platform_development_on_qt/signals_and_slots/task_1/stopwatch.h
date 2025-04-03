#pragma once

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    Stopwatch(QObject *parent = 0);

public slots:
    void startStop();
    void reset();
    void round();

private slots:
    void updateTime();

private:
    int milliseconds;
    int round_count;
    QTimer timer;

signals:
    void timeUpdated(QString &timeText);
    void requestTime(QString text);
};
