include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console thread
CONFIG -= app_bundle qt pipe

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# C++11
QMAKE_CXXFLAGS += -std=c++11

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

# ncurses
LIBS += -lncurses


HEADERS += \
    Ball_init.h \
    Common_misc.h \
    Game_init.h \
    Game_run.h \
    Labyrinth_addSnake.h \
    Labyrinth_displayHandler.h \
    Labyrinth_generateBal.h \
    Labyrinth_load.h \
    Labyrinth_save.h \
    Labyrinth_setLabyrinth.h \
    Snake_init.h \
    Snake_move.h \
    Snake_setDirection.h \
    shared.h \
    ../app/Change/change.h \
    ../app/Common/common.h \
    ../app/Ball/ball.h \
    ../app/Game/game.h \
    ../app/Labyrinth/labyrinth.h \
    ../app/Snake/snake.h

SOURCES += main.cpp \
    ../app/Change/change.cpp \
    ../app/Common/common.cpp \
    ../app/Ball/ball.cpp \
    ../app/Game/game.cpp \
    ../app/Labyrinth/labyrinth.cpp \
    ../app/Labyrinth/displayHandler.cpp \
    ../app/Snake/snake.cpp \

INCLUDEPATH += ../app
