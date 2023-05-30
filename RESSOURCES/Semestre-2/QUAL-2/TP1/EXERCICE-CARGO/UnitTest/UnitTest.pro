QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_merchandisetest.cpp \
    ../App/merchandise.cpp

HEADERS += \
    ../App/merchandise.h
