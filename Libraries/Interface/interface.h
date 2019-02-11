#ifndef INTERFACE_H
#define INTERFACE_H
#include "menu.h"
#include "navigator.h"

/**
 * Basic class of the console widget (to store different widgets in one list)
 */
class Widget
{
    public:
        virtual void focus(int index);
        virtual void unfocus(int index);
};

#endif
