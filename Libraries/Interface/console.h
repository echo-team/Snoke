#ifndef CONSOLE_H
#define CONSOLE_H
#include "interface.h"

/**
 * The root widget (singleton)
 */
class Console : private Widget
{
    private:
        Console();
        Console(const Console&);
        Console& operator=(Console&);

    public:
        static Console& instance();
        using Widget::add;
        using Widget::parent;
        Geometry geometry();
        void execute();
        void _refresh();
        void _touch();
};

/**
 * Instance of the root widget class
 * @type {Console&}
 */
extern Console& console;

#endif
