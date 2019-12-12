#-------------------------------------------------
#
# Project created by QtCreator 2019-12-08T13:09:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeoBachelor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dropdowntoolbutton.cpp \
    myview.cpp \
    grid.cpp \
    mathobject.cpp \
    point.cpp \
    line.cpp \
    circle.cpp \
    Triangle.cpp \
    general_functions.cpp

HEADERS += \
        mainwindow.h \
    dropdowntoolbutton.h \
    myview.h \
    grid.h \
    mathobject.h \
    point.hpp \
    line.hpp \
    circle.hpp \
    Triangle.hpp \
    general_functions.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
