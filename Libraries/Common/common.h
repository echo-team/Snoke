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

/**
 * Coordinates of the cell in console window
 * @prop {short} x - x coordinate in console window
 * @prop {short} y - y coordinate in console window
 */
typedef struct {
    short x, y;
} Point;

/**
 * Geometry of the rectangle
 * @prop {short} width  - rectangle width
 * @prop {short} height - rectangle height
 */
typedef struct {
    short width, height;
} Geometry;

/**
 * Style of the cell in console window
 * @prop {char}  letter - symbol in the cell
 * @prop {short} fg     - foreground color of the cell
 * @prop {short} bg     - beckground color of the cell
 */
typedef struct 
{
    char letter;
    int fg, bg;
} PointStyle;

std::ostream& operator << (std::ostream &s, Point p);
bool operator == (Point p1, Point p2);
void mSleep(int time);
bool inAddChange(Point p, Point* change[2], int changeSize);
bool inRemChange(Point p, Point* change[2], int changeSize);
Point getConsoleSize();

#endif
