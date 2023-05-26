set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_library(CitiesInformation STATIC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

target_sources(CitiesInformation
    PRIVATE
    citydata.h
    citydata.cpp
    citydatamodel.h
    citydatamodel.cpp
    citydataparser.h
    citydataparser.cpp
    EnumConverter.h
    PUBLIC
    resources.qrc)

target_link_libraries(CitiesInformation
  PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
)
