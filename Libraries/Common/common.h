#ifndef COMMON_H
#define COMMON_H
#include <ncurses.h>


/**
 * Style of the cell in console window
 * @prop {char}  letter - symbol in the cell
 * @prop {short} fg     - foreground color of the cell
 * @prop {short} bg     - beckground color of the cell
 */
typedef struct
{
	char letter;
	short fg, bg;
} PointStyle;

/**
 * Coordinates of the cell in console window
 * @prop {short} x - x coordinate in console window
 * @prop {short} y - y coordinate in console window
 */
typedef struct
{
	short x, y;
} Point;

/**
 * Gets size of current console screen in symdols
 * @return {Point} size
 */
Point getConsoleSize();

#endif
