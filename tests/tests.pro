include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# C++11
QMAKE_CXXFLAGS += -std=c++11

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

# ncurses
LIBS += -lncurses


HEADERS += snake_init_test.h \
    shared.h \
    ../app/Common/common.h \
    ../app/Ball/ball.h \
    ../app/Game/game.h \
    ../app/Labyrinth/labyrinth.h \
    ../app/Snake/snake.h \
    snake_setdirection_test.h

SOURCES += main.cpp \
    ../app/Common/common.cpp \
    ../app/Ball/ball.cpp \
    ../app/Game/game.cpp \
    ../app/Labyrinth/labyrinth.cpp \
    ../app/Snake/snake.cpp \

INCLUDEPATH += ../app
