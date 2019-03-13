#include "navigator.h"

/**
 * Gets widgets next sibling
 * @param  {Widget*} widget - widget to get sibling
 * @return {Widget*}        - if widget is last in parents widgets array, then NULL
 */
Widget* Navigator::sibling(Widget* widget)
{
    Widget* parent = current->parent();
    std::vector<Widget*> children = parent->children();
    Widget* next = std::find(children.begin(), children.end(), widget);

    if (next != children.end())
    {
        return next;
    }
    else
    {
        return NULL;
    }
}

/**
 * Finds a next clickable widget with focus event
 * @return {Widget*} - if nothing found, then NULL
 */
Widget* Navigator::next()
{
    if (current == NULL && root->children().size() > 0)
    {
        current = root->children()[0];
    }

    bool diving = true;
    while (current != NULL)
    {
        if (current == root)
        {
            current = NULL;
        }
        else if (current->event(EVENT_FOCUS))
        {
            return current;
        }
        else
        {
            if (diving && current->children().size())
            {
                current = current->children()[0];
            }
            else if (Widget* next = sibling(current))
            {
                diving = true;
                current = next;
            }
            else
            {
                diving = false;
                current = current->parent();
            }
        }
    }

    return current;
}

/**
 * @constructor
 * @paran {Widget*} root - instance of the root widget (Console class)
 */
Navigator::Navigator(Widget* root) :
    current(NULL), root(root)
{}
