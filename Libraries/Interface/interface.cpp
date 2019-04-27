#include "interface.h"

/**
 * Drawing widget method
 * @virtual
 */
void Widget::draw()
{}

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
