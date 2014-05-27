#-------------------------------------------------
#
# Project created by QtCreator 2014-05-26T17:09:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UTProfiler_P14_Brocheton_Goerens
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Cursus.cpp \
    UV.cpp \
    UVManager.cpp \
    CursusManager.cpp

HEADERS  += mainwindow.h \
    Cursus.h \
    enum.h \
    includes.h \
    UV.h \
    UVManager.h \
    CursusManager.h \
    singletonTemplate.h

FORMS    += mainwindow.ui
