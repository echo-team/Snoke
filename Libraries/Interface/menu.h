#ifndef MENU_H
#define MENU_H
#include <ncurses.h>
#include <cstring>
#include <list>
#include "interface.h"

/**
 * Describes menu button
 * @prop {const char*} name - text drawn at the button
 */
class MenuItem : public Widget
{
    private:
        int x, y;
        const char* name;

    public:
        void draw();
        MenuItem(const char* name, int x, int y);
};

/**
 * Menu (list of selestable items) widget class
 * @prop  {list<MenuButton>} buttons - buttons included in menu
 * @prop {int}              x       - x coordinate of left menu side
 * @prop {int}              y       - y coordinate of top menu side
 * @prop {int}              width   - menu width
 * @prop {int}              height  - menu height
 */
class Menu : public Widget
{
    private:
        int x, y, width, height;

    public:
        using Widget::add;
        void add(const char* name);
        void focus(int index);
        void unfocus(int index);
        void draw();
        Menu(int x, int y, int width, int height);
};

#endif
