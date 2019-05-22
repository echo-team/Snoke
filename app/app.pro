# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = Snoke

LIBS += -lncurses

HEADERS = \
   Ball/ball.h \
   Change/change.h \
   Common/common.h \
   Game/game.h \
   Labyrinth/labyrinth.h \
    Screens/application.h \
   Screens/mainMenu.h \
    Screens/screen.h \
   SideMenu/SideMenu.h \
   Snake/snake.h \ \
    Widgets/logo.h \
    Widgets/menu.h \
    Widgets/widget.h

SOURCES = \
   Ball/ball.cpp \
   Change/change.cpp \
   Common/common.cpp \
   Game/game.cpp \
   Labyrinth/displayHandler.cpp \
   Labyrinth/labyrinth.cpp \
   Screens/application.cpp \
   Screens/mainMenu.cpp \
   Screens/screen.cpp \
   SideMenu/SideMenu.cpp \
   Snake/snake.cpp \
   Main.cpp \
   Widgets/logo.cpp \
   Widgets/menu.cpp \
   Widgets/widget.cpp

INCLUDEPATH = \
    Ball \
    Change \
    Common \
    Game \
    Labyrinth \
    Screens \
    SideMenu \
    Snake

#DEFINES =
