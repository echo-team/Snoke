#include "screen.h"

/**
 * Adds widget to the object model of the screen
 * @param {Widget*} widget - new widget to include
 */
void Screen::add(Widget* widget)
{
    model.push_back(widget);
    widget.draw();
}

/**
 * Getts the pointer to the first widget in model
 * @return {std::list<Widget*>::iterator}
 */
std::list<Widget*>::iterator previous(std::list<Widget*>::iterator current)
{
    return model.begin();
}

/**
 * Getts the pointer to the previous widget in model
 * @return {std::list<Widget*>::iterator}
 */
std::list<Widget*>::iterator previous(std::list<Widget*>::iterator current)
{
    if (current == model.begin())
    {
        return model.end() - 1;
    }

    return current - 1;
}

/**
 * Getts the pointer to the next widget in model
 * @return {std::list<Widget*>::iterator}
 */
std::list<Widget*>::iterator next(std::list<Widget*>::iterator current)
{
    if (current == model.end() + 1)
    {
        return model.begin();
    }

    return current + 1;
}
