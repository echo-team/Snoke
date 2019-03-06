#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>

/**
 * Arguments for align methods
 * @const {char} ALIGN_LEFT   - left align
 * @const {char} ALIGN_RIGHT  - right align
 * @const {char} ALIGN_CENTER - center align
 * @const {char} ALIGN_TOP    - top align
 * @const {char} ALIGN_BOTTOM - bottom align
 * @const {char} ALIGN_NONE   - resets align to default
 * @const {char} ALIGN_IGNORE - use to ignore value if you want to set only 1 align
 */
#define ALIGN_LEFT   : 'l'
#define ALIGN_RIGHT  : 'r'
#define ALIGN_CENTER : 'c'
#define ALIGN_TOP    : 't'
#define ALIGN_BOTTOM : 'b'
#define ALIGN_NONE   : 'n'
#define ALIGN_IGNORE : 'n'

/**
 * Arguments for position methods
 * @const {char} POS_NONE   - reset position to activate alignment
 * @const {char} POS_IGNORE - use if you want to set only 1 coordinate
 */
#define POS_NONE   : -1
#define POS_IGNORE : -2

/**
 * Basic class of the console widget (to store different widgets in one list)
 * @prop {short}           x            - x-coordinate of the widget or POS_ constant
 * @prop {short}           y            - y-coordinate of the widget or POS_ constant
 * @prop {Point}           client       - 'client' (real) calculated coordinates, updates by update() method
 * @prop {short}           width        - width
 * @prop {short}           height       - height
 * @prop {char[2]}         align        - alignment, left top for default, if set x, y not works
 * @prop {char}            align[0]     - if 'l' left, if 'c' - center, if 'r' - right (see ALIGN_ constants)
 * @prop {char}            align[1]     - if 't' top, if 'c' - center, if 'b' - bottom (see ALIGN_ constants)
 * @prop {vector<Widget*>} children     - children of current widget
 * @prop {Widget}          parentWidget - parent of current widget
 * @prop {WINDOW*}         frame        - ncurces implementation of widget
 */
class Widget
{
    private:
        short x, y, width, height;
        Point client;
        char align;
        Widget* parentWidget;
        std::vector<Widget*> children;
        WINDOW* frame;
        void calculateClientPosition();
        void moveCursor();
    public:
        virtual void draw();
        virtual void focus(int index);
        virtual void unfocus(int index);
        void align(char horizontal, char vertical);
        void position(short x, short y);
        void geometry(short width, short height);
        void add(Widget* child);
        Point position();
        Geometry geometry();
        Widget* parent();
        void update();
        void _parent(Widget* parent);
        void _refresh();
        void _touch();
        Widget();

};

#include "navigator.h"
#include "menu.h"
#endif
