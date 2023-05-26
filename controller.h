#pragma once

#include <QObject>
#include <QFutureWatcher>
#include <QQmlEngine>
#include <QQmlListProperty>
#include "CitiesInformation/citydata.h"

class Controller : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(Cities cities READ cities NOTIFY citiesChanged)

public:
    Controller(QObject *parent = nullptr);

    void parse_city_database() const;

    [[nodiscard]] std::vector<CityData> cities() const;
    void setCities(const std::vector<CityData> &cities);

signals:
    void citiesChanged();
    void parsingFinished();

private:
    void handleParsingFinished();

    std::vector<CityData> m_cities;

};
