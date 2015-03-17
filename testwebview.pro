#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T15:19:25
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = testwebview
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    CustomStyle.h

FORMS    += widget.ui
