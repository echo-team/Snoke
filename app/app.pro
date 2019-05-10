# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = Snoke

LIBS = -lncurses

HEADERS = \
   Ball/ball.h \
   Common/common.h \
   Game/game.h \
   Interface/interface.h \
   Interface/logo.h \
   Interface/menu.h \
   Interface/navigator.h \
   Labyrinth/labyrinth.h \
   Screens/mainMenu.h \
   SideMenu/SideMenu.h \
   Snake/snake.h

SOURCES = \
   Ball/ball.cpp \
   Common/common.cpp \
   Game/game.cpp \
   Interface/interface.cpp \
   Interface/logo.cpp \
   Interface/menu.cpp \
   Interface/navigator.cpp \
   Labyrinth/labyrinth.cpp \
   Screens/mainMenu.cpp \
   SideMenu/SideMenu.cpp \
   Snake/snake.cpp \
   Main.cpp

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
