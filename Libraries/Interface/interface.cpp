#include "interface.h"
#include <iostream>

/**
 * Calculates 'client' position from align
 */
void Widget::calculateClientPosition()
{
    Geometry field = parentWidget->geometry();
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
 */
void Widget::focus()
{}

/**
 * Event listener activated by Navigator module when user clicks on widget
 * @virtual
 * @callback Navigator::listener
 */
void Widget::unfocus()
{}

/**
 * Sets align of widget
 * @param {char} horizontal - horisontal align (see ALIGN_ constants)
 * @param {char} vertical   - vertical align (see ALIGN_ constants)
 */
void Widget::alignment(char horizontal, char vertical)
{
    align[0] = horizontal == ALIGN_IGNORE ? align[0] : horizontal;
    align[1] = vertical == ALIGN_IGNORE ? align[1] : vertical;
}

/**
 * Sets x and y start coords of the widget
 * @param {short} x - x-coordinate of the widget
 * @param {short} y - y-coordinate of the widget
 */
void Widget::position(short x, short y)
{
    this->x = x == POS_IGNORE ? this->x : x;
    this->y = y == POS_IGNORE ? this->y : y;
}

/**
 * Getter for coordinates of widget
 * @return {Point}
 */
Point Widget::position()
{
    return client;
}

/**
 * Sets width and height of the widget
 * @param {short} width  - width
 * @param {short} height - height
 */
void Widget::geometry(short width, short height)
{
    this->width = width;
    this->height = height;
}

/**
 * Getter for sizes of widget
 * @return {Geometry}
 */
Geometry Widget::geometry()
{
    return {width, height};
}

/**
 * Checks if listeners are set for given event
 * @param  {unsigned char} event - id of event to check
 * @return {bool}                - true if listeners are specified false if not
 */
bool Widget::event(unsigned char event)
{
    if (listeners[event].size())
    {
        return true;
    }

    return false;
}

/**
 * Runs listeners binded to specified evend of current widget
 * @param {unsigned char} event - id of event to check
 */
void Widget::dispatch(unsigned char event)
{
    for (int counter = 0; counter < listeners[event].size(); counter++)
    {
        listeners[event][counter]();
    }
}

/**
 * Binds listener to widget event
 * @param {unsigned char}  event    - id of event
 * @param {const listener} listener - method handing event
 */
void Widget::addListener(unsigned char event, Listener listener)
{
    std::map<unsigned char, std::vector<Listener> >::iterator existing = listeners.find(event);

    if (existing != listeners.end())
    {
        existing->second.push_back(listener);
    }
    else
    {
        listeners.insert(std::pair<unsigned char, std::vector<Listener>>(event, {listener}));
    }
}

/**
 * Adds child to current widget and draws it
 * @param {Widget*} child - new child of current widget
 */
void Widget::add(Widget* child)
{
    childWidgets.push_back(child);
    child->_parent(this);
    child->update();
}

/**
 * Returns parent of widget
 * @return {Widget*}
 */
Widget* Widget::parent()
{
    return parentWidget;
}

/**
 * Returns children of current widget
 * @return {std::vector<Widget*>}
 */
std::vector<Widget*> Widget::children()
{
    return childWidgets;
}

/**
 * Updates (redraws) widget, if ncurses window isn't set yet, creates it
 */
void Widget::update()
{
    /**
     * Calculate position for widget in relative (for getter) and in absolute (for ncurses window definition)
     */
    calculateClientPosition();

    Widget* current = parent();
    Point absolute = client;

    while (current != NULL)
    {
        Point delta = current->position();
        absolute.x += delta.x;
        absolute.y += delta.y;

        current = current->parent();
    }

    /**
     * If widget wasn't shown create ncurses window for it
     */
    if (frame == NULL)
    {
        frame = newwin(height, width, absolute.y, absolute.x);
    }

    /**
     * Redraws parent and current (touched by changing of current) widgets
     */
    draw();
    //parentWidget->_touch();
    //parentWidget->_refresh();
    Widget::_refresh();
}

/**
 * Hidden setter for parent property (uses only when child widget places on screen)
 * @param {Widget*} parent - new parent in the DOM tree
 */
void Widget::_parent(Widget* parent)
{
    if (parentWidget == NULL)
    {
        parentWidget = parent;
    }
}

/**
 * Hidden function for updating current widget
 */
void Widget::_refresh()
{
    wrefresh(frame);
}

/**
 * Hidden function for saving covered by children areas of parent
 */
void Widget::_touch()
{
    touchwin(frame);
}


/**
 * @constructor
 */
Widget::Widget() :
    x(-1), y(-1),
    client({0, 0}),
    width(0), height(0),
    align({'l', 't'}),
    parentWidget(NULL), frame(NULL)
{}
