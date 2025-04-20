#include "stats.h"
#include "ui_stats.h"

#include <QSqlQuery>

Stats::Stats(const QPair<QString, QString> &airport, DataBase* db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Stats), m_airport(airport), database(db)
{
    ui->setupUi(this);

    ui->cb_months->addItem("Январь", 1);
    ui->cb_months->addItem("Февраль", 2);
    ui->cb_months->addItem("Март", 3);
    ui->cb_months->addItem("Апрель", 4);
    ui->cb_months->addItem("Май", 5);
    ui->cb_months->addItem("Июнь", 6);
    ui->cb_months->addItem("Июль", 7);
    ui->cb_months->addItem("Август", 8);
    ui->cb_months->addItem("Сентябрь", 9);
    ui->cb_months->addItem("Октябрь", 10);
    ui->cb_months->addItem("Ноябрь", 11);
    ui->cb_months->addItem("Декабрь", 12);

    ui->lb_airport->setText(m_airport.second);
    connect(database, &DataBase::sig_displayYearStat, this, &Stats::DisplayYearStat);
    database->requestToYearStat(m_airport.first);

    connect(ui->cb_months, &QComboBox::currentIndexChanged, this, [=]{
        int month = ui->cb_months->currentData().toInt();
        database->requestToMonthStat(m_airport.first, month);
    });
    connect(database, &DataBase::sig_displayMonthStat, this, &Stats::DisplayMonthStat);
    database->requestToMonthStat(m_airport.first, 1);
}

void Stats::DisplayYearStat(const QVector<QPair<QDate, int>> &flightStats)
{
    ui->qp_year->clearPlottables();

    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> values;

    int index = 0;
    for (const auto& pair : flightStats) {
        ticks << index + 1;
        labels << pair.first.toString("MMM");
        values << pair.second;
        ++index;
    }
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);

    ui->qp_year->xAxis->setTicker(textTicker);
    ui->qp_year->xAxis->setTickLabelRotation(60);
    ui->qp_year->xAxis->setSubTicks(false);
    ui->qp_year->xAxis->setTickLength(0, 4);
    ui->qp_year->xAxis->setRange(0, ticks.size() + 1);
    ui->qp_year->xAxis->setLabel("Месяц");

    ui->qp_year->yAxis->setLabel("Кол-во рейсов");
    ui->qp_year->yAxis->setRange(0, *std::max_element(values.begin(), values.end()) * 1.2);

    QCPBars *bars = new QCPBars(ui->qp_year->xAxis, ui->qp_year->yAxis);
    bars->setWidth(0.6);
    bars->setData(ticks, values);
    bars->setName("Рейсы по месяцам");
    bars->setBrush(QColor(100, 150, 255));

    ui->qp_year->replot();
}

void Stats::DisplayMonthStat(const QVector<QPair<QDate, int>> &flightStat) {
    QCustomPlot *customPlot = ui->qp_month;
    customPlot->clearPlottables();
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    QVector<double> x, y;
    QMap<double, QString> labels;

    for (const auto &pair : flightStat) {
        int day = pair.first.day();
        int count = pair.second;

        x.append(day);
        y.append(count);

        labels[day] = pair.first.toString("dd");
    }

    QCPGraph *graph = customPlot->addGraph();
    graph->setData(x, y);
    graph->setPen(QPen(Qt::blue));
    graph->setLineStyle(QCPGraph::lsLine);
    graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    customPlot->xAxis->setLabel("День месяца");
    customPlot->yAxis->setLabel("Количество вылетов");
    customPlot->xAxis->setTickLabelRotation(60);

    int maxDay = *std::max_element(x.begin(), x.end());
    customPlot->xAxis->setRange(1, maxDay);
    customPlot->yAxis->setRange(0, *std::max_element(y.begin(), y.end()) + 1);

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (auto it = labels.begin(); it != labels.end(); ++it) {
        textTicker->addTick(it.key(), it.value());
    }
    customPlot->rescaleAxes();
    customPlot->xAxis->setTicker(textTicker);
    customPlot->replot();

}

void Stats::on_pb_close_clicked() {
    this->close();
}

Stats::~Stats()
{
    delete ui;
}
