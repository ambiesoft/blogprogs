TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += HAVE_IMAGE_HASH

SOURCES += main.cpp \
    pHash.cpp \
    ph_fft.c

HEADERS += \
    ph_fft.h \
    pHash.h \
    CImg.h
