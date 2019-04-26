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
 * Getts the amount of widget non-widget units (amount of times focus event will be parced)
 * @return {Widget*}
 */
short units()
{
    return _units;
}

/**
 * Setter for the amount of non-widget units
 * @return {Widget*}
 */
void units(short amount)
{
    _units = amount;
}
