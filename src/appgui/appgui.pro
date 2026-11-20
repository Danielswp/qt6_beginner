QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/../../bin/debug
} else {
    DESTDIR = $$PWD/../../bin/release
}


RC_ICONS = $$PWD/app.ico

SOURCES += \
    guidemo.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    guidemo.h \
    widget.h

FORMS += \
    widget.ui

