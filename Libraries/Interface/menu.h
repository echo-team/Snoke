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
typedef struct
{
    const char* name;
} MenuButton;

/**
 * Menu (list of selestable items) widget class
 * @prop  {list<MenuButton>} buttons - buttons included in menu
 */
class Menu : public Widget
{
    private:
        std::list<MenuButton> buttons;

    public:
        void addButton(const char* name);
        void focus(int index);
        void unfocus(int index);
        void draw();
        Menu();
};

#endif
