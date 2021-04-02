include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibcore

SOURCES += main.cpp \
    simple.cpp \
    scenario.cpp

HEADERS += \
    array.hpp \
    catch.hpp \
