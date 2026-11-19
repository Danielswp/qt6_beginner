QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/../../bin/debug
} else {
    DESTDIR = $$PWD/../../bin/release
}



SOURCES += \
    main.cpp \
    metademo.cpp \
    mymetaobj.cpp

HEADERS += \
    metademo.h \
    mymetaobj.h


FORMS +=

