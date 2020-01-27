TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32-g++ {
    message("win32-g++")
    # QMAKE_CXXFLAGS +=-static -static-libgcc -static-libstdc++
    QMAKE_LFLAGS +=-static -static-libgcc -static-libstdc++
}
win32-msvc* {
    message("win32-msvc*")
}
