#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>
#include <ncurses.h>
#include "../Common/common.h"

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
#define ALIGN_LEFT   'l'
#define ALIGN_RIGHT  'r'
#define ALIGN_CENTER 'c'
#define ALIGN_TOP    't'
#define ALIGN_BOTTOM 'b'
#define ALIGN_NONE   'n'
#define ALIGN_IGNORE 'n'

/**
 * Arguments for position methods
 * @const {short} POS_NONE   - reset position to activate alignment
 * @const {short} POS_IGNORE - use if you want to set only 1 coordinate
 */
#define POS_NONE   -1
#define POS_IGNORE -2

/**
 * Arguments for events methods
 * @const {unsigned char} EVENT_FOCUS  - event of focusing and unfocusing
 * @const {unsigned char} EVENT_ACTIVE - event of activating widget
 */
#define EVENT_FOCUS : 1
#define EVENT_FOCUS : 2

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
 * @prop {unsigned char}   events       - byte mask, keeping events which this widget holds
 * @prop {vector<Widget*>} childWidgets - children of current widget
 * @prop {Widget}          parentWidget - parent of current widget
 * @prop {WINDOW*}         frame        - ncurces implementation of widget
 */
class Widget
{
    private:
        Point client;
        char align[2];
        unsigned char events;
        Widget* parentWidget;
        std::vector<Widget*> childWidgets;
        void calculateClientPosition();

    protected:
        WINDOW* frame;
        short x, y, width, height;

    public:
        virtual void draw();
        virtual void focus(int index);
        virtual void unfocus(int index);
        void alignment(char horizontal, char vertical);
        void position(short x, short y);
        void geometry(short width, short height);
        void event(unsigned char name);
        void add(Widget* child);
        Point position();
        Geometry geometry();
        bool event(unsigned char name);
        Widget* parent();
        std::vector<Widget*> children();
        void update();
        void _parent(Widget* parent);
        void _refresh();
        void _touch();
        Widget();

};

#include "navigator.h"
#include "menu.h"
#endif
