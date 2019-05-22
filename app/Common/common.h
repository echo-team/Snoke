/**
 * @file common.h
 * @author Yegor Ignatov
 * @brief shared functions prototypes, structures, main classes declarations
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <ncurses.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN64
#include <windows.h>
#endif

#ifdef __unix__
#include <unistd.h>
#endif

const int MAXLINE = 256;

/**
 * @class PointStyle common.h
 * @brief   Style of the cell in console window
 * @prop letter - symbol in the cell
 * @prop fg - foreground color of the cell
 * @prop bg - background color of the cell
 */
class PointStyle
{
    public:
        char letter;
        int fg;
        int bg;
};

/**
 * @class Point common.h
 * @brief   Coordinates and style of the cell in console window
 * @prop    x       - x coordinate in console window
 * @prop    y       - y coordinate in console window
 * @prop    style   - style of the cell
 */
class Point
{
    public:
        short x;
        short y;
        PointStyle style;
        bool operator== (Point p);
};

/*
 * @brief   Class definitions for the individual files to know that they exist
 *          while being separetly compiled
 */
class Snake;
class Labyrinth;
class Game;
class Change;
class Ball;


std::ostream& operator<< (std::ostream &s, Point p);
void mSleep(int time);
void addSleep();
Point getConsoleSize();
void sleepHandler();

#ifndef __unix__
void set_escdelay(short mode);
#endif

#endif
