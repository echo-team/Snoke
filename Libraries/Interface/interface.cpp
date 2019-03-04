#include "interface.h"

/**
 * Event listener activated by Navigator module when user selects widget
 * @virtual
 * @callback Navigator::listener
 * @param {int} index - index of subunit of the widget
 */
void Widget::focus(int index)
{}

/**
 * Event listener activated by Navigator module when user clicks on widget
 * @virtual
 * @callback Navigator::listener
 * @param {int} index - index of subunit of the widget
 */
void Widget::unfocus(int index)
{}

/**
 * Sets align of widget
 * @param {char} horizontal - horisontal align (see ALIGN_ constants)
 * @param {char} vertical   - vertical align (see ALIGN_ constants)
 */
void align(char horizontal, char vertical)
{
    align[0] = horisontal == ALIGN_IGNORE ? align[0] : horizontal;
    align[1] = vertical == ALIGN_IGNORE ? align[1] : vertical;
}

/**
 * Sets x and y start coords of the widget
 * @param {int} x - x-coordinate of the widget
 * @param {int} y - y-coordinate of the widget
 */
void position(int x, int y)
{
    this->x = x;
    this->y = y;
}

/**
 * Sets width and height of the widget
 * @param {int} width  - width
 * @param {int} height - height
 */
void geometry(int width, int height)
{
    this->width = width;
    this->height = height;
}

/**
 * Adds child to current widget and draws it
 * @param {Widget*} child - new child of current widget
 */
void add(Widget* child)
{
    children.push_back(child);
    //TODO: add drawing
}

/**
 * @constructor
 * @param {char} horizontalAlign - align of widget on x axis (sets by ALIGN_ constants)
 * @param {char} verticalAlign   - align of widget on y axis (sets by ALIGN_ constants)
 * @param {int}  width           - width
 * @param {int}  height          - height
 */
Widget::Widget(char horizontalAlign, char verticalAlign, int width, int height) :
    x(0), y(0),
    width(width),
    height(height),
    align({horizontalAlign, verticalAlign})
{}

/**
 * @constructor
 * @param {int}  x             - x-coordinate of the widget
 * @param {char} verticalAlign - align of widget on y axis (sets by ALIGN_ constants)
 * @param {int}  width         - width
 * @param {int}  height        - height
 */
Widget::Widget(int x, char verticalAlign, int width, int height) :
    x(x), y(0),
    width(width),
    height(height),
    align({'n', verticalAlign})
{}

/**
 * @constructor
 * @param {char} horizontalAlign - align of widget on x axis (sets by ALIGN_ constants)
 * @param {int}  y               - y-coordinate of the widget
 * @param {int}  width           - width
 * @param {int}  height          - height
 */
Widget::Widget(char horizontalAlign, int y, int width, int height) :
    x(0), y(y),
    width(width),
    height(height),
    align({horizontalAlign, 'n'})
{}

/**
 * @constructor
 * @param {int} x          - x-coordinate of the widget
 * @param {int} y          - y-coordinate of the widget
 * @param {int} width      - width
 * @param {int} height     - height
 */
Widget::Widget(int x, int y, int width, int height) :
    x(x), y(y),
    width(width),
    height(height),
    align({'n', 'n'})
{}
