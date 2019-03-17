#ifndef TEXT_H
#define TEXT_H
#include <ncurses.h>
#include "interface.h"

/**
 * @prop {char*} innerText - text which widget contains
 */
class Text : public Widget
{
    private:
        char* innerText;

    public:
        void draw();
        void add(char* innerText);
        char* text();
        Text();
};

#endif
