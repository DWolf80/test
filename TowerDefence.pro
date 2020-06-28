QT       += core gui
QT       += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT+=widgets
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Enemy.cpp \
    MainStation.cpp \
    Selection.cpp \
    StationOne.cpp \
    StationThree.cpp \
    StationTwo.cpp \
    Stationparent.cpp \
    Stationpit.cpp \
    Structure.cpp \
    main.cpp \
    mainwindow.cpp \
    startfrom.cpp

HEADERS += \
    Enemy.h \
    MainStation.h \
    Selection.h \
    StationOne.h \
    StationThree.h \
    StationTwo.h \
    Stationparent.h \
    Stationpit.h \
    Structure.h \
    mainwindow.h \
    startfrom.h

FORMS += \
    startfrom.ui

RESOURCES += \
    images.qrc
