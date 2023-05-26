#include "citydataparser.h"

#include <QDebug>
#include <QFile>

static const auto kDatabaseFile = QStringLiteral(":/cities_db");

static auto const kCsvSeparator{","};
static auto const kNumberOfAttributes{11};

CityDataParser::CityDataParser()
{
}

//std::vector<CityData> CityDataParser::parse_file()
//{
//    return parse_file(kDatabaseFile);
//}

std::vector<CityData> CityDataParser::parse_file(const QString &cities_file)
{
    QFile file(cities_file);

    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << file.fileName() << file.errorString();
        return {};
    }

    std::vector<CityData> cities;

    bool header_processed = false;
    while(!file.atEnd()){
        auto const line = file.readLine();
        if(header_processed){
            auto const city_data = parse_file_line(line);
            if(city_data){
                cities.push_back(city_data.value());
            }
        } else {
            header_processed = true;
        }
    }
    return cities;
}

std::optional<CityData> CityDataParser::parse_file_line(const QByteArray &file_line)
{
    auto const trimmed_line = file_line.trimmed();

    auto const list = [&trimmed_line] () -> QStringList {
        auto string_list = QString{trimmed_line}.split("\"", Qt::KeepEmptyParts);
        string_list.removeAll(kCsvSeparator);
        if(!string_list.empty() && string_list.first().isEmpty()){
            string_list.removeFirst();
        }
        if(!string_list.empty() && string_list.last().isEmpty()){
            string_list.removeLast();
        }
        return string_list;
    }();

    if(list.count() != kNumberOfAttributes){
        return {};
    }

    return {list};
}
