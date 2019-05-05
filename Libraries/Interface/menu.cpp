#include "menu.h"

/**
 * Draws menu item
 */
void MenuItem::draw()
{
    move(y, x);
    printw(name);
}

/**
 * @constructor
 */
MenuItem::MenuItem(const char* name, int x, int y) : x(x), y(y), name(name)
{}

/**
 * Adds button to the menu
 * @param {const char*} name - text drawn at the button
 */
void Menu::add(const char* name)
{
    this->add(new MenuItem(name, x + 2, y + this->childLength() * 2));
}

/**
 * Event listener activated by Navigator module when user selects on widget
 * @override
 * @callback Navigator::listener
 * @param {int} index - index of subunit of the widget
 */
void Menu::focus(int index)
{
    move(y + index * 2 + 1, x);
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
    move(y + index * 2 + 1, x);
    printw(" ");
}

/**
 * Draws Menu in console window
 */
void Menu::draw()
{
    Widget* current = firstChild();
    while (current)
    {
        current->draw();
        current = current->next();
    }
}

/**
 * @constructor
 * @param {int} x      - x coordinate of left menu side
 * @param {int} y      - y coordinate of top menu side
 * @param {int} width  - menu width
 * @param {int} height - menu height
 */
Menu::Menu(int x, int y, int width, int height) : x(x), y(y), width(width), height(height)
{}
