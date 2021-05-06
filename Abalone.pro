TEMPLATE = subdirs
CONFIG += console

QMAKE_CFLAGS += -std=c17 \
-pedantic-errors

SUBDIRS += \
    core \
    tests \
    ui \
    console \

OTHER_FILES += \
    defaults.pri
