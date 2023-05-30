TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bankaccount.cpp \
        main.cpp \
        myexception.cpp

HEADERS += \
    bankaccount.h \
    myexception.h
