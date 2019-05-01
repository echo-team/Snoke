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
 * Style of the cell in console window
 * @prop {char}  letter - symbol in the cell
 * @prop {short} fg     - foreground color of the cell
 * @prop {short} bg     - beckground color of the cell
 */
typedef struct _PointStyle
{
    char letter;
    int fg, bg;
    _PointStyle& operator = (_PointStyle ps);
} PointStyle;

/**
 * Coordinates of the cell in console window
 * @prop {short} x - x coordinate in console window
 * @prop {short} y - y coordinate in console window
 */
typedef struct _Point
{
    short x, y;
    PointStyle style;
    _Point& operator = (_Point p);
} Point;

/**
 * Class definitions for the individual files to know that they exist
 * while being separetly compiled
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
