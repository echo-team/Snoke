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
 * Operation '<<' override for the Point type
 * @param  {std::ostream&} s - current ostream variable
 * @param  {Point}         p - 
 * @return {std::ostream&}
 * @override
 */
std::ostream& operator << (std::ostream &s, Point p);

/**
 * Comparison of Points
 * @param  {Point} p1 - first Point
 * @param  {Point} p2 - second Point
 * @return {Point}
 * @override
 */
bool operator == (Point p1, Point p2);

/**
 * Cross-platform sleep function cover
 * @param {int} time - time the game will 'freeze' for in milliseconds
 */
void mSleep(int time);

/**
 * Check if Points is in the addition queue
 * @param  {Point}     p       - point to check
 * @param  {Point*[2]} change  - array of changed Points
 * @return {bool}
 */
bool inAddChange(Point p, Point* change[2], int changeSize);

/**
 * Check if the Point is in the removal queue
 *
 * @param  {Point}     p       - point to check
 * @param  {Point*[2]} change  - array of changed Points
 * @return {bool}
 */
bool inRemChange(Point p, Point* change[2], int changeSize);

#endif