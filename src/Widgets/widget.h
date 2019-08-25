#ifndef INTERFACE_H
#define INTERFACE_H
#include <functional>
#include <map>
#include <list>
#include <vector>

/**
 * Arguments for events methods
 * @const {unsigned char} EVENT_FOCUS   - event of focusing
 * @const {unsigned char} EVENT_UNFOCUS - event of unfocusing
 * @const {unsigned char} EVENT_ACTIVE  - event of activating widget
 */
#define EVENT_FOCUS   1
#define EVENT_UNFOCUS 2
#define EVENT_ACTIVE  4

/**
 * Describes method called by event dispatching
 * @typedef {std::function<void()>} listener
 */
typedef std::function<void()> Listener;

/**
 * Basic class of the console widget (to store different widgets in one list)
 * Contains widgets tree for parsing events by Console class
 * @prop {Widget*}                                      parentWidget   - parent widget
 * @prop {Widget*}                                      start          - pointer to the first child of current widget
 * @prop {Widget*}                                      ending         - pointer to the last child of current widget
 * @prop {Widget*}                                      nextWidget     - pointer to the next sibling
 * @prop {Widget*}                                      previousWidget - pointer to the previous sibling
 * @prop {unsigned short}                               length         - amount of children
 * @prop {unsigned char}                                events         - binary store for events could be dispatched at current widget
 * @prop {std::map<unsigned char, std::list<Listener>>} listeners      - store for event listeners
 */
class Widget
{
    public:
        Widget* parentWidget;
        Widget* start;
        Widget* ending;
        Widget* nextWidget;
        Widget* previousWidget;
        unsigned short length;
        unsigned char events;
        std::map<unsigned char, std::list<Listener>> listeners;

    public:
        virtual void draw();
        void _parent(Widget* parentWidget);
        Widget* firstChild();
        Widget* lastChild();
        Widget* parent();
        void _next(Widget* nextWidget);
        Widget* next();
        void _previous(Widget* previousWidget);
        Widget* previous();
        void add(Widget* child);
        unsigned short childLength();
        std::vector<Widget*> children();
        bool event(unsigned char name);
        void listener(unsigned char name, Listener function);
        void dispatch(unsigned char name);
        Widget();
};

#endif
