#include "console.h"

/**
 * @constructor
 * Private plug for constructor in order to hold singularity of instance
 */
Console::Console() : Widget()
{}

/**
 * @constructor
 * Private plug for operator new (copy) in order to hold singularity of instance
 * @param {const Console&} - existing instance of console
 */
Console::Console(const Console&)
{}

/**
 * @constructor
 * Private plug for operator assignment in order to hold singularity of instance
 * @param {Console&} - existing instance of console
 */
Console& Console::operator=(Console&)
{}

/**
 * Getter for sizes of widget
 * @return {Geometry}
 */
Geometry Console::geometry()
{
    Geometry size;
    getmaxyx(stdscr, size.y, size.x);

    return size;
}

/**
 * Hidden function for updating current widget
 */
void _refresh()
{
    refresh();
}

/**
 * Hidden function for saving covered by children areas of parent
 */
void _touch()
{
    touchwin(stdscr);
}

/**
 * Returns link to the static Console instance defineg in Singleton class
 * @return {Console&}
 */
Console& Console::instance()
{
    static Console console;
    return console;
}
