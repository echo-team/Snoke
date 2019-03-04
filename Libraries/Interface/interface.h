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
 * Basic class of the console widget (to store different widgets in one list)
 * @prop {int}             x        - x-coordinate of the widget (default - 0, in percents if < 0)
 * @prop {int}             y        - y-coordinate of the widget (default - 0, in percents if < 0)
 * @prop {int}             width    - width (default - 0, in percents if < 0)
 * @prop {int}             height   - height (default - 0, in percents if < 0)
 * @prop {char[2]}         align    - alignment, left top for default, if set x, y not works
 * @prop {char}            align[0] - if 'l' left, if 'c' - center, if 'r' - right
 * @prop {char}            align[1] - if 't' top, if 'c' - center, if 'b' - bottom
 * @prop {vector<Widget*>} children - children of current widget
 * @prop {Widget}          parent   - parent of current widget
 */
class Widget
{
    private:
        int x, y, width, height;
        char align;
        Widget* parent;
        std::vector<Widget*> children;
    public:
        virtual void focus(int index);
        virtual void unfocus(int index);
        void align(char horizontal, char vertical);
        void position(int x, int y);
        void geometry(int width, int height);
        void add(Widget* child);
        Widget(char horizontalAlign, int y, int width, int height);
        Widget(int x, char verticalAlign, int width, int height);
        Widget(int char horizontalAlign, char verticalAlign, int width, int height);
        Widget(int x, int y, int width, int height);

};

#include "navigator.h"
#include "menu.h"
#endif
