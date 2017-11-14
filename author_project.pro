QT += core
QT -= gui

TARGET = author_project
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    testgit.cpp \
    text.cpp \
    block.cpp \
    features.cpp \
    distances.cpp

HEADERS += \
    testgit.h \
    text.h \
    block.h \
    features.h \
    distances.h

DISTFILES += \
    .gitignore

