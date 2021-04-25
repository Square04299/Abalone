TEMPLATE = subdirs
CONFIG += console

QMAKE_CFLAGS += -std=c17 \
-pedantic-errors

SUBDIRS += \
    core \
    tests \    
    console \
    ui \

OTHER_FILES += \
    defaults.pri
