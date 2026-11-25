QT       += core gui concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/../../bin/debug
} else {
    DESTDIR = $$PWD/../../bin/release
}


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    threaddemo.cpp \
    worker.cpp

HEADERS += \
    mainwindow.h \
    threaddemo.h \
    worker.h


FORMS += \
    mainwindow.ui

RESOURCES += \



