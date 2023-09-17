QT += widgets
requires(qtConfig(treeview))

HEADERS = DirViewer/DirViewer.h

SOURCES       = main.cpp
SOURCES       += DirViewer/DirViewer.cpp

CONFIG+=debug

# install
target.path = .
INSTALLS += target
