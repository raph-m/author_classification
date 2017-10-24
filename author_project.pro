QT += core
QT -= gui

TARGET = author_project
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    testgit.cpp

HEADERS += \
    testgit.h

DISTFILES += \
    .gitignore

