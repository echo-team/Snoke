#ifndef CONSOLE_H
#define CONSOLE_H
#include "interface.h"

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
        void _refresh();
        void _touch();
};
#endif
