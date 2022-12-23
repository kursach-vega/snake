QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    scr/main.cpp \
    scr/root.cpp \
    scr/tab_game.cpp \
    scr/snake.cpp \
    scr/field_object.cpp

HEADERS += \
    headers/root.hpp \
    headers/tab_game.hpp \
    headers/snake.hpp \
    headers/field_object.hpp

FORMS += \
    forms/root.ui

RESOURCES += \
    resources/resource.qrc

