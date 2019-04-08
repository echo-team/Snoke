#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include <algorithm>
#include <ncurses.h>
#include "interface.h"

/**
 * Class for working with object model of application (to find next clickable widget)
 * @prop {Widget*} current - selected widget
 * @prop {Widget*} root    - instance of the root widget (Console class)
 */
class Navigator
{
    private:
        Widget* current;
        Widget* root;
        Widget* nextSibling(Widget* widget);
        Widget* previousSibling(Widget* widget);

    public:
        Widget* next();
        Widget* previous();
        Navigator(Widget* root);
};

#endif
