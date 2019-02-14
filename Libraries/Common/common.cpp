#include "common.h"

/**
 * Gets size of current console screen in symdols
 * @return {Point} size
 */
Point getConsoleSize()
{
    Point size;
    getmaxyx(stdscr, size.y, size.x);

    return size;
}
