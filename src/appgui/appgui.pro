QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/../../bin/debug
} else {
    DESTDIR = $$PWD/../../bin/release
}


#RC_ICONS = $$PWD/app.ico

# 3rdparty
INCLUDEPATH += $$PWD/../../3rdparty/md4c/src
LIBS += -L"$$PWD/../../3rdparty/md4c/build/src/Debug" -lmd4c-html -lmd4c


SOURCES += \
    guidemo.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    guidemo.h \
    widget.h

FORMS += \
    widget.ui

RESOURCES += \
    Resources/resources.qrc

