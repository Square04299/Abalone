include(../defaults.pri)

TEMPLATE = lib
TARGET = libcore
DESTDIR = ../lib

HEADERS += \
    board.h \
    color.h \
    direction.h \
    game.h \
    player.h \
    position.h \
    square.h \
    state.h

SOURCES += \
    board.cpp \
    color.cpp \
    direction.cpp \
    game.cpp \
    player.cpp \
    position.cpp \
    square.cpp \
    state.cpp
