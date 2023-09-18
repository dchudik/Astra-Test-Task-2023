#include <QApplication>
#include "DirViewer/DirViewer.cpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    auto dirViewer = new DirViewer();
    auto dirViewerWidget = dirViewer->buildWidget();
    dirViewerWidget->show();

    return app.exec();
}
