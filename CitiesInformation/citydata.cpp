#include "citydata.h"
#include <QDebug>
#include <QList>
#include <QRegularExpression>

CityData::CityData()
{

}

CityData::CityData(const QString &name, const QString &ascii_name, float latitude, float longityde, const QString &country, const QString &country_iso2, const QString &country_iso3, const QString &country_admin_city, CityType capital, const QString &population, const QString &id) :
    m_name{name},
    m_ascii_name{ascii_name},
    m_latitude{latitude},
    m_longitude{longityde},
    m_country{country},
    m_country_iso2{country_iso2},
    m_country_iso3{country_iso3},
    m_country_admin_city{country_admin_city},
    m_capital{capital},
    m_population{population},
    m_id{id}
{

}

CityData::CityData(const QStringList &fields)
{
    m_name = fields.at(0);
    m_ascii_name = fields.at(1);
    m_latitude = fields.at(2).toFloat();
    m_longitude = fields.at(3).toFloat();
    m_country = fields.at(4);
    m_country_iso2 = fields.at(5);
    m_country_iso3 = fields.at(6);
    m_country_admin_city = fields.at(7);
    m_capital = fromString(fields.at(8));
    m_population = fields.at(9);
    m_id = fields.at(10);
}
const QString &CityData::name() const
{
    return m_name;
}

void CityData::setName(const QString &name)
{
    m_name = name;
}

const QString &CityData::ascii_name() const
{
    return m_ascii_name;
}

void CityData::setAscii_name(const QString &ascii_name)
{
    m_ascii_name = ascii_name;
}

float CityData::latitude() const
{
    return m_latitude;
}

void CityData::setLatitude(float latitude)
{
    m_latitude = latitude;
}

float CityData::longitude() const
{
    return m_longitude;
}

void CityData::setLongityde(float longityde)
{
    m_longitude = longityde;
}

const QString &CityData::country() const
{
    return m_country;
}

void CityData::setCountry(const QString &country)
{
    m_country = country;
}

const QString &CityData::country_iso2() const
{
    return m_country_iso2;
}

void CityData::setCountry_iso2(const QString &country_iso2)
{
    m_country_iso2 = country_iso2;
}

const QString &CityData::country_iso3() const
{
    return m_country_iso3;
}

void CityData::setCountry_iso3(const QString &country_iso3)
{
    m_country_iso3 = country_iso3;
}

const QString &CityData::country_admin_city() const
{
    return m_country_admin_city;
}

void CityData::setCountry_admin_city(const QString &country_admin_city)
{
    m_country_admin_city = country_admin_city;
}

CityData::CityType CityData::capital() const
{
    return m_capital;
}

void CityData::setCapital(CityType capital)
{
    m_capital = capital;
}

const QString &CityData::population() const
{
    return m_population;
}

void CityData::setPopulation(const QString &population)
{
    m_population = population;
}

const QString &CityData::id() const
{
    return m_id;
}

void CityData::setId(const QString &id)
{
    m_id = id;
}

bool CityData::is_valid() const
{
    return !m_name.isEmpty() &&
           !m_ascii_name.isEmpty() &&
           !m_country.isEmpty() &&
           !m_country_iso2.isEmpty() &&
           !m_country_iso3.isEmpty() &&
           !m_country_admin_city.isEmpty() &&
           !m_population.isEmpty() &&
           !m_id.isEmpty();
}

bool CityData::operator==(const CityData &other)
{
    return m_name  == other.name() &&
           m_ascii_name  == other.ascii_name() &&
           qFuzzyCompare(m_latitude,other.latitude()) &&
           qFuzzyCompare(m_longitude, other.longitude()) &&
           m_country  == other.country() &&
           m_country_iso2  == other.country_iso2() &&
           m_country_iso3  == other.country_iso3() &&
           m_country_admin_city  == other.country_admin_city() &&
           m_capital  == other.capital() &&
           m_population  == other.population() &&
           m_id == other.id();

}

CityData::CityType CityData::fromString(const QString &city_type_string) const
{
    if(city_type_string.isEmpty()){
        return CityType::Regular;
    }

    if(city_type_string.compare("primary", Qt::CaseInsensitive) == 0){
        return CityType::Capital;
    }

    if(city_type_string.compare("admin", Qt::CaseInsensitive) == 0){
        return CityType::FirstLevelCapital;
    }

    if(city_type_string.compare("minor", Qt::CaseInsensitive) == 0){
        return CityType::LowLevelCapital;
    }

    return CityType::Regular;
}
