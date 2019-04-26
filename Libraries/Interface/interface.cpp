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
 * Drawing widget method
 * @virtual
 */
void Widget::draw()
{}

/**
 * Getts the amount of widget non-widget units (amount of times focus event will be parced)
 * @return {Widget*}
 */
short Widget::units()
{
    return _units;
}

/**
 * Setter for the amount of non-widget units
 * @return {Widget*}
 */
void Widget::units(short amount)
{
    _units = amount;
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
 * @param {Event}         information - struct passed into called listeners
 */
void Widget::dispatch(unsigned char name, Event information)
{
    for (std::list<Listener>::iterator function = listeners[name].begin(); function != listeners[name].end(); function++)
    {
        (*function)(information);
    }
}
