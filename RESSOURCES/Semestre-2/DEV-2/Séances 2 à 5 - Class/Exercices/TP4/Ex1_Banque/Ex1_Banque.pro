TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        account.cpp \
        address.cpp \
        client.cpp \
        creditcard.cpp \
        main.cpp

HEADERS += \
    account.h \
    address.h \
    client.h \
    creditcard.h
