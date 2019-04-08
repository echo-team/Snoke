#include "console.h"
#include <iostream>

/**
 * @constructor
 * Private plug for constructor in order to hold singularity of instance
 */
Console::Console() : Widget()
{}

/**
 * Getter for sizes of widget
 * @return {Geometry}
 */
Geometry Console::geometry()
{
    Geometry size;
    getmaxyx(stdscr, size.height, size.width);

    return size;
}

/**
 * Runs main loop catching navigation events (arrow keys pressings)
 */
void Console::execute()
{
    Navigator navigator(this);
    Widget* widget = this;

    while (true)
    {
        short command = getch();

        switch(command)
        {
            case KEY_DOWN:
                widget->dispatch(EVENT_UNFOCUS);
                widget = navigator.next();
                widget->dispatch(EVENT_FOCUS);
                break;

            case KEY_UP:
                widget->dispatch(EVENT_UNFOCUS);
                widget = navigator.previous();
                widget->dispatch(EVENT_FOCUS);
                break;

            case 27:
                return;
        }
    }
}

/**
 * Hidden function for updating current widget
 */
void Console::_refresh()
{
    refresh();
    std::cout << "refreshed" << std::endl;
}

/**
 * Hidden function for saving covered by children areas of parent
 */
void Console::_touch()
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

Console& console = Console::instance();
