#include "screen.h"

/**
 * Adds widget to the object model of the screen
 * @param {Widget*} widget - new widget to include
 */
void Screen::add(Widget* widget)
{
    model.push_back(widget);
    widget->draw();
}

/**
 * Getts the pointer to the first widget in model
 * @return {std::list<Widget*>::iterator}
 */
std::list<Widget*>::iterator Screen::first()
{
    return model.begin();
}

/**
 * Getts the pointer to the previous widget in model
 * @return {std::list<Widget*>::iterator}
 */
std::list<Widget*>::iterator Screen::previous(std::list<Widget*>::iterator current)
{
    if (current == model.begin())
    {
        return std::prev(model.end(), 1);
    }

    return std::prev(current, 1);
}

/**
 * Getts the pointer to the next widget in model
 * @return {std::list<Widget*>::iterator}
 */
std::list<Widget*>::iterator Screen::next(std::list<Widget*>::iterator current)
{
    if (current == std::prev(model.end(), 1))
    {
        return model.begin();
    }

    return std::next(current, 1);
}

/**
 * Drawing screen method
 * @virtual
 */
void Screen::draw()
{}
