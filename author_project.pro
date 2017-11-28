QT += core
QT -= gui

TARGET = author_project
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Preprocessing/testgit.cpp \
    Preprocessing/text.cpp \
    Preprocessing/block.cpp \
    Preprocessing/features.cpp \
    mainvardon.cpp \
    mainarnaud.cpp

HEADERS += \
    Preprocessing/testgit.h \
    Preprocessing/text.h \
    Preprocessing/block.h \
    Preprocessing/features.h


DISTFILES += \
    .gitignore \
    100mostCommonWord.txt

