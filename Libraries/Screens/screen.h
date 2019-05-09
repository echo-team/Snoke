#ifndef SCREEN_H
#define SCREEN_H
#include <list>
#include "../Widgets/widget.h"

/**
 * Manages the widget tree
 * @prop {Widget*} root - pointer to the first vertex of screen widget tree
 */
class Screen
{
    protected:
        Widget* root;

    public:
        virtual void draw();
        Widget* first();
        Widget* next(Widget* current);
        Widget* previous(Widget* current);
        Screen();
};

#endif
