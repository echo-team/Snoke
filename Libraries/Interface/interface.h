#ifndef INTERFACE_H
#define INTERFACE_H
#include <functional>
#include <map>
#include <list>

/**
 * Arguments for events methods
 * @const {unsigned char} EVENT_FOCUS   - event of focusing
 * @const {unsigned char} EVENT_UNFOCUS - event of unfocusing
 * @const {unsigned char} EVENT_ACTIVE  - event of activating widget
 */
#define EVENT_FOCUS   1
#define EVENT_UNFOCUS 2
#define EVENT_ACTIVE  4

typedef struct
{
    short unit;
} Event;

/**
 * Describes method called by event dispatching
 * @typedef {std::function<void()>} listener
 */
typedef std::function<void(Event)> Listener;

/**
 * Basic class of the console widget (to store different widgets in one list)
 * @prop {short}                                        _units    - amount of non-widget children
 * @prop {unsigned char}                                events    - binary store for events could be dispatched at current widget
 * @prop {std::map<unsigned char, std::list<Listener>>} listeners - store for event listeners
 */
class Widget
{
    public:
        short _units;
        unsigned char events;
        std::map<unsigned char, std::list<Listener>> listeners;

    public:
        virtual void focus(int index);
        virtual void unfocus(int index);
        virtual void draw();
        short units();
        void units(short amount);
        bool event(unsigned char name);
        void listener(unsigned char name, Listener function);
        void dispatch(unsigned char name, Event information);
};

#endif
