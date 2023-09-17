#include <QApplication>
// #include "DirViewer/DirViewer.h"
#include "DirViewer/DirViewer.cpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    qDebug() << "Constructor";
    auto dirViewer = new DirViewer();
    qDebug() << "Get widget";
    auto dirViewerWidget = dirViewer->buildWidget();
    dirViewerWidget->show();

    return app.exec();
}
