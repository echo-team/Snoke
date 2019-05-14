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


HEADERS += snake_init_test.h \
    ball_init_test.h \
    common_test.h \
    game_init_test.h \
    labyrinth_addsnake_test.h \
    labyrinth_displayhandler_test.h \
    labyrinth_generateball_test.h \
    labyrinth_load_test.h \
    labyrinth_save_test.h \
    labyrinth_setlabyrinth_test.h \
    shared.h \
    ../app/Change/change.h \
    ../app/Common/common.h \
    ../app/Ball/ball.h \
    ../app/Game/game.h \
    ../app/Labyrinth/labyrinth.h \
    ../app/Snake/snake.h \
    snake_move_test.h \
    snake_setdirection_test.h

SOURCES += main.cpp \
    ../app/Change/change.cpp \
    ../app/Common/common.cpp \
    ../app/Ball/ball.cpp \
    ../app/Game/game.cpp \
    ../app/Labyrinth/labyrinth.cpp \
    ../app/Labyrinth/displayHandler.cpp \
    ../app/Snake/snake.cpp \

INCLUDEPATH += ../app
