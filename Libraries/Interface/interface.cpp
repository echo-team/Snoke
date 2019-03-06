#include "interface.h"

/**
 * Calculates 'client' position from align
 */
void getClientPosition()
{
    Geometry field = parentNode->geometry();
    client.x = x;
    client.y = y;

    if (x == POS_NONE)
    {
        switch(align[0])
        {
            case ALIGN_LEFT:
                client.x = 0;
                break;
            case ALIGN_CENTER:
                client.x = (field.width - width) / 2;
                break;
            case ALIGN_RIGHT:
                client.x = field.width - width;
                break;
        }
    }

    if (y == POS_NONE)
    {
        switch(align[1])
        {
            case ALIGN_TOP:
                client.y = 0;
                break;
            case ALIGN_CENTER:
                client.y = (field.height - height) / 2;
                break;
            case ALIGN_BOTTOM:
                client.y = field.height - height;
                break;
        }
    }
}

/**
 * Draws widget
 * @virtual
 * @callback Widget::update
 */
void Widget::draw()
{}

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
 * @param {short} x - x-coordinate of the widget
 * @param {short} y - y-coordinate of the widget
 */
void position(short x, short y)
{
    this->x = x == POS_IGNORE ? this->x : x;
    this->y = y == POS_IGNORE ? this->y : y;
}

/**
 * Getter for coordinates of widget
 * @return {Point}
 */
Point position()
{
    return client;
}

/**
 * Sets width and height of the widget
 * @param {short} width  - width
 * @param {short} height - height
 */
void geometry(short width, short height)
{
    this->width = width;
    this->height = height;
}

/**
 * Getter for sizes of widget
 * @return {Geometry}
 */
Geometry geometry()
{
    return {width, height};
}

/**
 * Adds child to current widget and draws it
 * @param {Widget*} child - new child of current widget
 */
void add(Widget* child)
{
    children.push_back(child);
    child->_parent(this);
    child->update();
}

/**
 * Returns parent of widget
 * @return {Widget*}
 */
Widget* parent()
{
    return parentWidget;
}

/**
 * Updates (redraws) widget, if ncurses window isn't set yet, creates it
 */
void update()
{
    /**
     * Calculate position for widget in relative (for getter) and in absolute (for ncurses window definition)
     */
    calculateClientPosition();

    Widget* current = parent();
    Point absolute = client;

    while (current != NULL)
    {
        Point delta = current.position();
        absolute.x += current.x;
        absolute.y += current.y;

        current = current->parent();
    }

    /**
     * If widget wasn't shown create ncurses window for it
     */
    if (frame == NULL)
    {
        frame = newwin(height, width, y, x);
    }

    /**
     * Redraws parent and current (touched by changing of current) widgets
     */
    draw();
    parent->_touch();
    parent->_refresh();
    _refresh();
}

/**
 * Hidden setter for parent property (uses only when child widget places on screen)
 * @param {Widget*} parent - new parent in the DOM tree
 */
void _parent(Widget* parent)
{
    if (parentWidget == NULL)
    {
        parentWidget = parent;
    }
}

/**
 * Hidden function for updating current widget
 */
void _refresh()
{
    wrefresh(frame);
}

/**
 * Hidden function for saving covered by children areas of parent
 */
void _touch()
{
    touchwin(frame);
}


/**
 * @constructor
 */
Widget::Widget() :
    x(-1), y(-1),
    client({0, 0}),
    width(0),
    height(0),
    align({'l', 't'})
{}
