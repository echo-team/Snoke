#ifndef SCREEN_H
#define SCREEN_H
#include <list>
#include "../Interface/interface.h"

/**
 * Manages the object model and
 * @prop {std::list<Widget*>} model - object model of the screen
 */
class Screen
{
    private:
        std::list<Widget*> model;

    public:
        void add(Widget* widget);
        std::list<Widget*>::iterator first();
        std::list<Widget*>::iterator previous(std::list<Widget*>::iterator current);
        std::list<Widget*>::iterator next(std::list<Widget*>::iterator current);
        virtual void draw();
};

#endif
