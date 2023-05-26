#pragma once

#include "citydata.h"

#include <optional>
#include <vector>

class CityDataParser
{
public:
    CityDataParser();
//    static std::vector<CityData> parse_file();
    static std::vector<CityData> parse_file(const QString &cities_file);
private:
    static std::optional<CityData> parse_file_line(const QByteArray &file_line);
};
