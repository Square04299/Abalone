include(../defaults.pri)

TEMPLATE = lib
TARGET = libcore
DESTDIR = ../lib

HEADERS += \
    Board.h \
    Color.h \
    Game.h \
    Marble.h \
    Player.h \
    State.h

SOURCES += \
    Board.cpp \
    Color.cpp \
    Game.cpp \
    Marble.cpp \
    Player.cpp \
    State.cpp
