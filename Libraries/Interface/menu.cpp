#include "menu.h"
#include <iostream>

/**
 * Adds button to the menu
 * @param {const char*} name - text drawn at the button
 */
void Menu::addButton(const char* name)
{
    buttons.push_back({name});
}

/**
 * Event listener activated by Navigator module when user selects on widget
 * @override
 * @callback Navigator::listener
 * @param {int} index - index of subunit of the widget
 */
void Menu::focus(int index)
{
    wmove(frame, index * 2 + 1, 0);
    printw(">");
}

/**
 * Event listener activated by Navigator module when user removes selection from widget
 * @override
 * @callback Navigator::listener
 * @param {int} index - index of subunit of the widget
 */
void Menu::unfocus(int index)
{
    wmove(frame, index * 2 + 1, 0);
    printw(" ");
}

/**
 * Draws Menu in console window
 */
void Menu::draw()
{
    int yCounter = 1;

    for (std::list<MenuButton>::iterator currentButton = buttons.begin(); currentButton != buttons.end(); currentButton++)
    {
        wmove(frame, yCounter, 2 + (width - strlen(currentButton->name)) / 2);
        wprintw(frame, currentButton->name);
        yCounter += 2;
    }
}

/**
 * @constructor
 */
Menu::Menu() : Widget()
{}
