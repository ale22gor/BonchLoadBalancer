#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "model.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();
    Model myModel;

    ctxt->setContextProperty("myModel", &myModel);


    ctxt->setContextProperty("AdmUnitsModel", QVariant::fromValue(myModel.getAdmUnitsModel()));
    ctxt->setContextProperty("CoursesNamesListModel", QVariant::fromValue(myModel.getCoursesNamesModel()));
    ctxt->setContextProperty("ProffesorsNamesListModel", QVariant::fromValue(myModel.getProffesorsNamesModel()));
    ctxt->setContextProperty("ProffesorsSubCoursesList", QVariant::fromValue(myModel.getProffesorsDetailModel()));

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
