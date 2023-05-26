#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QJSEngine>

#include "controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/WeatherCompass/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    QScopedPointer<Controller> controller{new Controller(&app)};
    qmlRegisterSingletonInstance("com.weathercompass", 1, 0, "Controller", controller.get());
    QQmlEngine::setObjectOwnership(controller.get(), QQmlEngine::CppOwnership);
    engine.load(url);
    controller->parse_city_database();

    return app.exec();
}
