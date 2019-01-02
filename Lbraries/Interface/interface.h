/**
 * Basic class of the console widget (to store different widgets in one list)
 */
class Widget
{
    public:
        virtual void focus(int index);
        virtual void unfocus(int index);
};

#include "interface.cpp"
#include "menu.h"
#include "navigator.h"
