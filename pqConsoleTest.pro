#-------------------------------------------------
#
# Project created by QtCreator 2013-06-14T15:37:10
#
#-------------------------------------------------

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pqConsoleTest
TEMPLATE = app

# please, not obsolete compiler
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../pqConsole/release/ -lpqConsole
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../pqConsole/debug/ -lpqConsole
else:symbian: LIBS += -lpqConsole
else:unix: LIBS += -L$$OUT_PWD/../pqConsole/ -lpqConsole

INCLUDEPATH += $$PWD/../pqConsole
DEPENDPATH += $$PWD/../pqConsole

RESOURCES +=

unix:!symbian {
    # because SWI-Prolog is built from source
    CONFIG += link_pkgconfig
    PKGCONFIG += swipl
}
windows {
    SwiPl = "C:\Program Files\pl"
    INCLUDEPATH += $$SwiPl\include
    LIBS += -L$$SwiPl\bin -lswipl
}

OTHER_FILES += \
    README.md
