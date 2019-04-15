#-------------------------------------------------
#
# Project created by QtCreator 2019-01-08T09:17:15
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alarm_server
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
        window.cpp \
    reaudiodata.cpp \
    global.cpp \
    alarm/alarmapm.cpp \
    alarm/yxt/qReader.cpp \
    alarm/yxt/qRedis.cpp \
    alarm/yxt/qredismanager.cpp \
    alarm/senddata.cpp \
    alarm/alarmsimilar.cpp \
    alarm/similarthread.cpp \
    AudioTransfer/dirrefresh.cpp \
    AudioTransfer/transferfile.cpp \
    sql/mysql.cpp \
    sql/secondlog.cpp

HEADERS += \
        window.h \
    reaudiodata.h \
    global.h \
    alarm/alarmapm.h \
    alarm/yxt/qReader.h \
    alarm/yxt/qRedis.h \
    alarm/yxt/qredismanager.h \
    alarm/senddata.h \
    alarm/alarmsimilar.h \
    alarm/similarthread.h \
    AudioTransfer/dirrefresh.h \
    AudioTransfer/transferfile.h \
    sql/mysql.h \
    sql/secondlog.h

FORMS += \
        window.ui
DEFINES += QT_MESSAGELOGCONTEXT
##CONFIG += console pro
include( $$PWD/JQLibrary/JQCPUMonitor.pri )
