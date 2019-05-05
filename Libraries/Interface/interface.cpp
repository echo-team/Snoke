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
 * Setts next widget
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
 * Setts previous widget
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
    if (firstChild == NULL)
    {
        firstChild = child;
        return;
    }

    Widget* previousChild = firstChild;
    while (previousChild->next() != NULL)
    {
        previousChild = previousChild->next();
    }

    previousChild->_next(child);
    this->_previous(previousChild);
}

/**
 * Returns array of child widgets
 * @return {std::vector<Widget*>}
 */
std::vector<Widget*> Widget::children()
{
    std::vector<Widget*> childWidgets;
    Widget* child = firstChild;

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
 * Setts listener to the event
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
 * @param {unsigned char} name        - name of the event
 */
void Widget::dispatch(unsigned char name)
{
    for (std::list<Listener>::iterator function = listeners[name].begin(); function != listeners[name].end(); function++)
    {
        (*function)();
    }
}
