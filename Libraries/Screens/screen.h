#ifndef SCREEN_H
#define SCREEN_H
#include <list>
#include "../Interface/interface.h"

/**
 * Manages the widget tree
 * @prop {Widget*} root - pointer to the first vertex of screen widget tree
 */
class Screen
{
    private:
        Widget* root;

    public:
        virtual void draw();
        Screen();
};

#endif
