# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = Snoke

LIBS = -lncurses

HEADERS = \
   $$PWD/Libraries/Ball/ball.h \
   $$PWD/Libraries/Common/common.h \
   $$PWD/Libraries/Game/game.h \
   $$PWD/Libraries/Interface/interface.h \
   $$PWD/Libraries/Interface/logo.h \
   $$PWD/Libraries/Interface/menu.h \
   $$PWD/Libraries/Interface/navigator.h \
   $$PWD/Libraries/Labyrinth/labyrinth.h \
   $$PWD/Libraries/Screens/mainMenu.h \
   $$PWD/Libraries/SideMenu/SideMenu.h \
   $$PWD/Libraries/Snake/snake.h

SOURCES = \
   $$PWD/Libraries/Ball/ball.cpp \
   $$PWD/Libraries/Common/common.cpp \
   $$PWD/Libraries/Game/game.cpp \
   $$PWD/Libraries/Interface/interface.cpp \
   $$PWD/Libraries/Interface/logo.cpp \
   $$PWD/Libraries/Interface/menu.cpp \
   $$PWD/Libraries/Interface/navigator.cpp \
   $$PWD/Libraries/Labyrinth/labyrinth.cpp \
   $$PWD/Libraries/Screens/mainMenu.cpp \
   $$PWD/Libraries/SideMenu/SideMenu.cpp \
   $$PWD/Libraries/Snake/snake.cpp \
   $$PWD/Main.cpp

INCLUDEPATH = \
    $$PWD/Libraries/Ball \
    $$PWD/Libraries/Common \
    $$PWD/Libraries/Game \
    $$PWD/Libraries/Interface \
    $$PWD/Libraries/Labyrinth \
    $$PWD/Libraries/Screens \
    $$PWD/Libraries/SideMenu \
    $$PWD/Libraries/Snake

#DEFINES = 

