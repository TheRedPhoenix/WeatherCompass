#pragma once

#include <QByteArray>
#include <QObject>
#include <QString>

class CityData
{
    Q_GADGET
public:
    enum class CityType {
        Regular,
        LowLevelCapital,
        FirstLevelCapital,
        Capital
    };

    CityData();
    CityData(const QString &name,
             const QString &ascii_name,
             float latitude,
             float longityde,
             const QString &country,
             const QString &country_iso2,
             const QString &country_iso3,
             const QString &country_admin_city,
             CityType capital,
             const QString &population,
             const QString &id);

    CityData(const QStringList& fields);

    [[nodiscard]] const QString &name() const;
    void setName(const QString &name);

    [[nodiscard]] const QString &ascii_name() const;
    void setAscii_name(const QString &ascii_name);

    [[nodiscard]] float latitude() const;
    void setLatitude(float latitude);

    [[nodiscard]] float longitude() const;
    void setLongityde(float longityde);

    [[nodiscard]] const QString &country() const;
    void setCountry(const QString &country);

    [[nodiscard]] const QString &country_iso2() const;
    void setCountry_iso2(const QString &country_iso2);

    [[nodiscard]] const QString &country_iso3() const;
    void setCountry_iso3(const QString &country_iso3);

    [[nodiscard]] const QString &country_admin_city() const;
    void setCountry_admin_city(const QString &country_admin_city);

    [[nodiscard]] CityType capital() const;
    void setCapital(CityType capital);

    [[nodiscard]] const QString &population() const;
    void setPopulation(const QString &population);

    [[nodiscard]] const QString &id() const;
    void setId(const QString &id);

    bool is_valid() const;

    bool operator==(const CityData &other);

private:

    CityType fromString(const QString& city_type_string) const;

    QString     m_name;
    QString     m_ascii_name;
    float       m_latitude;
    float       m_longitude;
    QString     m_country;
    QString     m_country_iso2;
    QString     m_country_iso3;
    QString     m_country_admin_city;
    CityType    m_capital;
    QString     m_population;
    QString     m_id;

};

using Cities = std::vector<CityData>;

Q_DECLARE_METATYPE(CityData)
Q_DECLARE_METATYPE(Cities)
