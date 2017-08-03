#-------------------------------------------------
#
# Project created by QtCreator 2016-08-18T19:20:26
#
#-------------------------------------------------
QT       += widgets
QT       += core gui
QT       += serialport
QT       += bluetooth

QMAKE_LFLAGS_RELEASE += -static -static-libgcc


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Desktop
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    settingsdialog.cpp \
    serial_port.cpp

HEADERS  += widget.h \
    settingsdialog.h \
    serial_port.h

FORMS    += widget.ui \
    settingsdialog.ui
