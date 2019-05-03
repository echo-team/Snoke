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

#define MAXLINE 256

/**
 * @struct _PointStyle common.h
 * @brief   Style of the cell in console window
 */
typedef struct _PointStyle
{
    /**
     * @prop    char    letter
     * @brief   symbol in the cell
     */
    char letter;
    /**
     * @prop    int     fg
     * @brief   foreground color of the cell
     */
    int fg;
    /**
     * @prop    int     bg
     * @brief   background color of the cell
     */
    int bg;
    _PointStyle& operator = (_PointStyle ps);
} PointStyle;

/**
 * @struct _Point common.h
 * @brief   Coordinates and style of the cell in console window
 */
typedef struct _Point
{
    /**
     * @prop    short       x
     * @brief   x coordinate in console window
     */
    short x;
    /**
     * @prop    short       y
     * @brief   y coordinate in console window
     */
    short y;
    /**
     * @prop    PointStyle  style
     * @brief   style of the cell
     */
    PointStyle style;
    _Point& operator = (_Point p);
} Point;

/*
 * @brief   Class definitions for the individual files to know that they exist
 *          while being separetly compiled
 */
class Snake;
class Labyrinth;
class Game;
class Ball;

std::ostream& operator << (std::ostream &s, Point p);
bool operator == (Point p1, Point p2);
void mSleep(int time);
bool inAddChange(Point p, Point* change[2], int changeSize);
bool inRemChange(Point p, Point* change[2], int changeSize);
Point getConsoleSize();

#endif
