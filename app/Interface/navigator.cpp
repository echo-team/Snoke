#include "navigator.h"

/**
 * Adds selectable widget to the end of selectable widgets queue
 * @param {Widget*} unit           - seleclable widget
 * @param {int }    subunitsAmount - amount of subwidgets
 */
void Navigator::pushUnit(Widget* unit, int subunitsAmount)
{
    units.push_back({unit, subunitsAmount});
}

/**
 * Starts main loop of application to catch selections and activate events done by user
 */
void Navigator::listen()
{
    curs_set(0);
    keypad(stdscr, true);
    noecho();
    currentUnit = units.begin();
    currentSubunit = 0;
    currentUnit->widget->focus(currentSubunit);

    while (1)
    {
        int command = getch();

        if (command != ERR)
        {
            switch(command)
            {
                case (KEY_UP):

                    currentUnit->widget->unfocus(currentSubunit);
                    if (currentSubunit > 0)
                    {
                        currentSubunit--;
                    }
                    else if (currentUnit != units.begin())
                    {
                        currentUnit--;
                        currentSubunit = currentUnit->subunitsAmount - 1;
                    }
                    currentUnit->widget->focus(currentSubunit);
                    break;

                case (KEY_DOWN):

                    currentUnit->widget->unfocus(currentSubunit);
                    if (currentSubunit < currentUnit->subunitsAmount - 1)
                    {
                        currentSubunit++;
                    }
                    else if (std::distance(units.begin(), currentUnit) + 1 < (unsigned int)units.size())
                    {
                        currentUnit++;
                        currentSubunit = 0;
                    }

                    move(0, 0);
                    currentUnit->widget->focus(currentSubunit);
                    break;
            }
        }
    }
}

/**
 * @constructor
 */
Navigator::Navigator()
{
    currentUnit = units.begin();
    currentSubunit = 0;
}
