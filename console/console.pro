include(../defaults.pri)

#you MUST include headers to subprojects, for instance like this
#"core" is not added here because it's already in defaults.pri

#INCLUDEPATH += $$PWD/../controllers

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibcore \

SOURCES += main.cpp \
    Observable.cpp \
    Observer.cpp \
    View.cpp

HEADERS += \
    Observable.h \
    Observer.h \
    View.h
