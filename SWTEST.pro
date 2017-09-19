QT += core
QT -= gui
QT += serialport

CONFIG += c++11

TARGET = SWTEST
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    LIBRARY/SWITCH/borlsw.cpp \
    LIBRARY/SERIALCOM/serialcom.cpp \
    LIBRARY/POWERDETECT/borlpowdetect.cpp \
    LIBRARY/AOTF/borlfianium.cpp \
    power_recorder.cpp
    # debugging in OS X, this lib is only supported in Win OS
    power_recorder.cpp\

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    LIBRARY/SWITCH/borlsw.h \
    LIBRARY/SWITCH/borlsw_global.h \
    LIBRARY/SERIALCOM/serialcom.h \
    LIBRARY/POWERDETECT/borlpowdetect.h \
    LIBRARY/AOTF/borlfianium.h\
    # debugging in OS X, this lib is only supported in Win OS
    power_recorder.h



win32: LIBS += -L$$PWD/../NOCC-PRIVATE/ -lAotfLibrary


INCLUDEPATH += $$PWD/LIBRARY/AOTF  \
$$PWD/LIBRARY/SWITCH \
$$PWD/LIBRARY/SERIALCOM \
$$PWD/LIBRARY/POWERDETECT\
$$PWD/../NOCC_PRIVATE

DEPENDPATH +=  $$PWD/LIBRARY/AOTF  \
$$PWD/LIBRARY/SWITCH \
$$PWD/LIBRARY/SERIALCOM \
$$PWD/LIBRARY/POWERDETECT\
$$PWD/../NOCC_PRIVATE


win32: LIBS += -L$$PWD/../NOCC_PRIVATE/ -lAotfLibrary

INCLUDEPATH += $$PWD/../NOCC_PRIVATE
DEPENDPATH += $$PWD/../NOCC_PRIVATE
