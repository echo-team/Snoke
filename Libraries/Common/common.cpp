#ifndef COMMON_H
#define COMMON_H
#include <iostream>

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
 * @override Operation '<<' override for the Point type
 */
inline std::ostream& operator << (std::ostream &s, Point p)
{
    s << '(' << p.x << ',' << p.y << ')';
    return s;
}

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


/**
 * Cross-platform sleep function cover
 * @param {int} time - time the game will 'freeze' for in milliseconds
 */
inline void mSleep(int time)
{
#ifdef _WIN32
    Sleep(time);

#elif defined(_WIN64)
    Sleep(time);
#endif

#ifdef __unix__
    usleep(time*1000);
#endif
}

#endif