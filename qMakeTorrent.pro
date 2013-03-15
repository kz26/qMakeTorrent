#-------------------------------------------------
#
# Project created by QtCreator 2013-03-10T19:48:06
#
#-------------------------------------------------

QT       += core gui

TARGET = qMakeTorrent
TEMPLATE = app


SOURCES += main.cpp\
        wizard.cpp \
    intropage.cpp \
    inputpage.cpp \
    trackerspage.cpp \
    propertiespage.cpp \
    creationpage.cpp \
    createtorrent.cpp \
    outputpage.cpp

HEADERS  += wizard.h \
    intropage.h \
    inputpage.h \
    trackerspage.h \
    propertiespage.h \
    creationpage.h \
    version.h \
    createtorrent.h \
    outputpage.h

FORMS += \
    wizard.ui \
    intropage.ui \
    inputpage.ui \
    trackerspage.ui \
    propertiespage.ui \
    creationpage.ui \
    outputpage.ui

LIBS += -lboost_system -ltorrent-rasterbar -lboost_filesystem

OTHER_FILES += \
    readme.md
