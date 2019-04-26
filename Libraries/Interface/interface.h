#ifndef INTERFACE_H
#define INTERFACE_H

/**
 * Basic class of the console widget (to store different widgets in one list)
 * @prop {Widget*} _next     - next widget in the object model
 * @prop {Widget*} _previous - previous widget in the object model
 */
class Widget
{
    public:
        short _units;

    public:
        virtual void focus(int index);
        virtual void unfocus(int index);
        virtual void draw();
        short units();
        void units(short amount);
};

#endif
