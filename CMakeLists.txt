cmake_minimum_required(VERSION 3.16)

project(WeatherCompass VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Concurrent)
find_package(Qt6 REQUIRED COMPONENTS Core Quick Concurrent)

add_subdirectory(CitiesInformation)

qt_standard_project_setup()

qt_add_executable(appWeatherCompass
    main.cpp
    controller.h
    controller.cpp
)

qt_add_qml_module(appWeatherCompass
    URI WeatherCompass
    VERSION 1.0
    QML_FILES Main.qml
)

set_target_properties(appWeatherCompass PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appWeatherCompass
    PUBLIC CitiesInformation
    PRIVATE Qt6::Core Qt6::Quick Qt6::Concurrent
)

install(TARGETS appWeatherCompass
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
