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
 * Gets size of current console screen in symdols
 * @return {Point} size
 */
Point getConsoleSize()
{
    Point size;
    getmaxyx(stdscr, size.y, size.x);

    return size;
}
