#pragma once

#include <QAbstractTableModel>

#include "citydata.h"

class CityDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum class Column {
        Name = 0,
        NameAscii,
        Latitude,
        Longitude,
        Country,
        Iso2,
        Iso3,
        AdminName,
        Capital,
        Population,
        Id,
        Max
    };

    explicit CityDataModel(QObject *parent = nullptr);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    [[nodiscard]] const std::vector<CityData> &cities() const;
    void setCities(const std::vector<CityData> &cities);

private:
    std::vector<CityData> m_cities;
};

