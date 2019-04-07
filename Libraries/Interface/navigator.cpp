#include "navigator.h"

/**
 * Gets widgets next sibling
 * @param  {Widget*} widget - widget to get sibling
 * @return {Widget*}        - if widget is last in parents widgets array, then NULL
 */
Widget* Navigator::nextSibling(Widget* widget)
{
    Widget* parent = current->parent();
    std::vector<Widget*> children = parent->children();
    short index = std::find(children.begin(), children.end(), widget) - children.begin() + 1;
    std::cout << "next index: " << index << std::endl;

    if (index < children.size())
    {
        return children[index];
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
    int which = 0;
    while (current != NULL)
    {
        std::cout << current << " " << which << std::endl;

        if (current->parent() == NULL)
        {
            current = NULL;
        }
        else if (current->event(EVENT_FOCUS))
        {
            return current;
        }
        else
        {
            Widget* next = nextSibling(current);

            if (diving && current->children().size())
            {
                current = current->children()[0];
                which = 0;
            }
            else if (next != NULL)
            {
                diving = true;
                current = next;
                which = 1;
            }
            else
            {
                diving = false;
                current = current->parent();
                which = 2;
            }
        }
    }
    std::cout << std::endl;

    return current;
}

/**
 * @constructor
 * @paran {Widget*} root - instance of the root widget (Console class)
 */
Navigator::Navigator(Widget* root) :
    current(NULL), root(root)
{}
