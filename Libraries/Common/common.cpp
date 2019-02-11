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
 * Operation '<<' override for the Point type
 * @param  {std::ostream&} s - current ostream variable
 * @param  {Point}         p - 
 * @return {std::ostream&}
 * @override
 */
inline std::ostream& operator << (std::ostream &s, Point p)
{
    s << '(' << p.x << ',' << p.y << ')';
    return s;
}


/**
 * Comparison of Points
 * @param  {Point} p1 - first Point
 * @param  {Point} p2 - second Point
 * @return {Point}
 * @override
 */
inline bool operator == (Point p1, Point p2)
{
    return (p1.x == p2.x and p1.y == p2.y);
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

/**
 * Check if Points is in the addition queue
 * @param  {Point}     p       - point to check
 * @param  {Point*[2]} change  - array of changed Points
 * @return {bool}
 */
inline bool inAddChange(Point p, Point* change[2], int changeSize)
{
    for (int i = 0; i < changeSize; i++)
    {
        if(change[0][i] == p)
        {
            return true;
        }
    }
    return false;
}

/**
 * Check if the Point is in the removal queue
 *
 * @param  {Point}     p       - point to check
 * @param  {Point*[2]} change  - array of changed Points
 * @return {bool}
 */
inline bool inRemChange(Point p, Point* change[2], int changeSize)
{
    for (int i = 0; i < changeSize; i++)
    {
        if(change[1][i] == p)
        {
            return true;
        }
    }
    return false;
}

#endif