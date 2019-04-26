#ifndef INTERFACE_H
#define INTERFACE_H

/**
 * Basic class of the console widget (to store different widgets in one list)
 * @prop {Widget*} _next     - next widget in the object model
 * @prop {Widget*} _previous - previous widget in the object model
 */
class Widget
{
    public:
        Widget* _next, _previous;
        short _units;

    public:
        virtual void focus(int index);
        virtual void unfocus(int index);
        short units();
        void units(short amount);
};

#include "navigator.h"
#include "menu.h"
#endif
