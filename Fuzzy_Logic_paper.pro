TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fuzzycontroler.cpp \
        main.cpp \
        membership.cpp \
        point.cpp \
        range.cpp \
        rule.cpp

HEADERS += \
    fuzzycontroler.h \
    membership.h \
    point.h \
    range.h \
    rule.h
