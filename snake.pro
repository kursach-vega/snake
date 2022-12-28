QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = Snake

SOURCES += \
    scr/main.cpp \
    scr/root.cpp \
    scr/tab_game.cpp \
    scr/snake.cpp \
    scr/field_object.cpp \
    scr/draw_image.cpp \
    scr/music.cpp 

HEADERS += \
    headers/root.hpp \
    headers/tab_game.hpp \
    headers/snake.hpp \
    headers/field_object.hpp \
    headers/draw_image.hpp \
    headers/music.hpp 

FORMS += \
    forms/root.ui

RESOURCES += \
    resources/resource.qrc

