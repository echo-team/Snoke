#include "menu.h"

/**
 * Draws menu item
 */
void MenuItem::draw()
{
    mvaddstr(y, x, name);
}

/**
 * @constructor
 */
MenuItem::MenuItem(const char* name, int x, int y, int width, int height) : Widget(), x(x), y(y), width(width), height(height), name(name)
{}

/**
 * Adds button to the menu
 * @param {const char*} name - text drawn at the button
 */
void Menu::add(const char* name)
{
    MenuItem* item = new MenuItem(name, x + (width - strlen(name)) / 2, y + this->childLength() * 2, strlen(name), 1);
    item->listener(EVENT_FOCUS, std::bind(&Menu::focus, this, this->childLength()));
    item->listener(EVENT_UNFOCUS, std::bind(&Menu::unfocus, this, this->childLength()));
    this->add(item);
}

/**
 * Event listener activated by Navigator module when user selects on widget
 * @override
 * @callback Navigator::listener
 * @param {int} index - index of subunit of the widget
 */
void Menu::focus(int index)
{
    mvaddch(y + index * 2, x, '>');
    refresh();
}

/**
 * Event listener activated by Navigator module when user removes selection from widget
 * @override
 * @callback Navigator::listener
 * @param {int} index - index of subunit of the widget
 */
void Menu::unfocus(int index)
{
    mvaddch(y + index * 2, x, ' ');
    refresh();
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
Menu::Menu(int x, int y, int width, int height) : Widget(), x(x), y(y), width(width), height(height)
{}
