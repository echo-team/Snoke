#include "interface.h"

/**
 * Drawing widget method
 * @virtual
 */
void Widget::draw()
{}

/**
 * Setter for parent property
 * @param {Widget*} parentWidget - new parent widget
 */
void Widget::_parent(Widget* parentWidget)
{
    this->parentWidget = parentWidget;
}

/**
 * Getter for parent property
 * @return
 */
Widget* Widget::parent()
{
    return parentWidget;
}

/**
 * Returns first child of widget
 * @return {Widget*}
 */
Widget* Widget::firstChild()
{
    return start;
}

/**
 * Returns last child of widget
 * @return {Widget*}
 */
Widget* Widget::lastChild()
{
    return ending;
}

/**
 * Sets next widget
 * @param {Widget*} nextWidget - new next widget
 */
void Widget::_next(Widget* nextWidget)
{
    this->nextWidget = nextWidget;
}

/**
 * Getter for next widget
 * @return {Widget*}
 */
Widget* Widget::next()
{
    return nextWidget;
}

/**
 * Sets previous widget
 * @param {Widget*} previousWidget - new previous widget
 */
void Widget::_previous(Widget* previousWidget)
{
    this->previousWidget = previousWidget;
}

/**
 * Getter for previous widget
 * @return {Widget*}
 */
Widget* Widget::previous()
{
    return previousWidget;
}

/**
 * Adds a new child to the current widget
 * @param {Widget*} child - new child widget
 */
void Widget::add(Widget* child)
{
    length++;
    child->_parent(this);
    this->ending = child;

    if (start == NULL)
    {
        start = child;
        return;
    }

    Widget* previousChild = start;
    while (previousChild->next() != NULL)
    {
        previousChild = previousChild->next();
    }

    previousChild->_next(child);
    child->_previous(previousChild);
}

/**
 * Returns amount of children
 * @return {unsigned short}
 */
unsigned short Widget::childLength()
{
    return length;
}

/**
 * Returns array of child widgets
 * @return {std::vector<Widget*>}
 */
std::vector<Widget*> Widget::children()
{
    std::vector<Widget*> childWidgets;
    Widget* child = start;

    while (child != NULL)
    {
        childWidgets.push_back(child);
        child = child->next();
    }

    return childWidgets;
}

/**
 * Checks if event is dispatchable
 * @param  {unsigned char} name - name of the event
 * @return {bool}               - true if event listeners are existing and active
 */
bool Widget::event(unsigned char name)
{
    return events & name;
}

/**
 * Sets listener to the event
 * @param {unsigned char} name     - name of the event
 * @param {Listener}      function - event listener function
 */
void Widget::listener(unsigned char name, Listener function)
{
    listeners[name].push_back(function);
    events = events | name;
}

/**
 * Dispatches event on widget
 * Calls all event listeners binded on given event to the widget
 * @param {unsigned char} name - name of the event
 */
void Widget::dispatch(unsigned char name)
{
    for (auto function = listeners[name].begin(); function != listeners[name].end(); function++)
    {
        (*function)();
    }
}

/**
 * @constructor
 */
Widget::Widget() : parentWidget(NULL), start(NULL), ending(NULL), nextWidget(NULL), previousWidget(NULL), length(0)
{}
