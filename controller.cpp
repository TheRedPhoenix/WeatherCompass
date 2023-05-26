#include "controller.h"

#include <QPointer>
#include <QDebug>
#include <QFile>
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

#include "CitiesInformation/citydataparser.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    // use qt smart-storage feature for QObject children
    auto * watcher = new QFutureWatcher<Cities>(this);
    connect(watcher, &QFutureWatcher<Cities>::finished, this, &Controller::handleParsingFinished);
}

void Controller::parse_city_database() const
{
    auto * watcher = this->findChild<QFutureWatcher<Cities>*>();
    if(watcher){
        auto const filepath = QStringLiteral(":/cities_db");
        const auto future = QtConcurrent::run(CityDataParser::parse_file, filepath);
        watcher->setFuture(future);
    }
}

void Controller::handleParsingFinished()
{
    auto * watcher = this->findChild<QFutureWatcher<Cities>*>();
    if(watcher && watcher->isFinished() && !watcher->isCanceled()){
        auto const cities = watcher->result();
        setCities(cities);
    }
    emit parsingFinished();
}

std::vector<CityData> Controller::cities() const
{
    return m_cities;
}

void Controller::setCities(const std::vector<CityData> &cities)
{
    m_cities = cities;
    emit citiesChanged();
}
