#include "citydatamodel.h"
#include "EnumConverter.h"
#include <QIcon>

CityDataModel::CityDataModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int CityDataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_cities.size();
}

int CityDataModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return +Column::Max;
}

QVariant CityDataModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= rowCount()){
        return {};
    }

    if(index.column() < 0 || index.column() >= columnCount()){
        return {};
    }

    auto const city = m_cities.at(index.row());

    switch(role){
    case Qt::DisplayRole:
        switch(index.column()){
        case +Column::Name:
            return city.name();
        case +Column::NameAscii:
            return city.ascii_name();
        case +Column::Latitude:
            return city.latitude();
        case +Column::Longitude:
            return city.longitude();
        case +Column::Country:
            return city.country();
        case +Column::Iso2:
            return city.country_iso2();
        case +Column::Iso3:
            return city.country_iso3();
        case +Column::AdminName:
            return city.country_admin_city();
        case +Column::Capital:
            return QVariant::fromValue(city.capital());
        case +Column::Population:
            return city.population();
        case +Column::Id:
            return city.id();
        }
        return {};
    case Qt::DecorationRole:
        return QIcon{QStringLiteral(":/resources/40x30/%1.png").arg(city.country_iso2())};
    default:
        return {};
    }
}

QVariant CityDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // TODO: implement feature
    return {};
}

const std::vector<CityData> &CityDataModel::cities() const
{
    return m_cities;
}

void CityDataModel::setCities(const std::vector<CityData> &cities)
{
    beginResetModel();
    m_cities = cities;
    endResetModel();
}
