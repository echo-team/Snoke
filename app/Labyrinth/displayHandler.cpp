#include "labyrinth.h"


void DisplayHandler::displayHandler(int displayMethod)
{
    /*
     * checking if we are beeing asked to use a certain method
     */
    if(displayMethod >= 0)
    {
        this->forcedDisplay(displayMethod);
    }
    else
    {
        this->freeDisplay();
    }
    refresh();
    flushinp();
}
/**
 * @brief   got an extra stimulus for displaying in a certain method
 * @param   displayMethod   - a method that is beeing force-called
 */
void DisplayHandler::forcedDisplay(int displayMethod)
{
    /*
     * Deciding what disply method to use
     */
    switch (displayMethod)
    {
        case DISPFULL:
        {
            if(labyrinth->start.x == 0 && labyrinth->end.x == gameFieldSize.x && labyrinth->start.y == 0 && labyrinth->end.y == gameFieldSize.y)
            {
                this->displayFull();
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        case DISPUPD:
        {
            if(labyrinth->start.x == 0 && labyrinth->end.x == gameFieldSize.x && labyrinth->start.y == 0 && labyrinth->end.y == gameFieldSize.y)
            {
                this->displayUpdated();
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        case DISPPART:
        {
            this->displayPartialy();
            break;
        }
        default:
        {
            this->displayPartialy();
        }
    }
}

/**
 * @brief   No extra stimulus, displaying the default way
 */
void DisplayHandler::freeDisplay()
{
    /*
     * Deciding what disply method to use
     */
    switch (this->prevDisplayMethod)
    {
        case DISPFULL:
        {
            if(labyrinth->start.x == 0 && labyrinth->end.x == gameFieldSize.x && labyrinth->start.y == 0 && labyrinth->end.y == gameFieldSize.y)
            {
                this->displayUpdated();
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        case DISPUPD:
        {
            if(labyrinth->start.x == 0 && labyrinth->end.x == gameFieldSize.x && labyrinth->start.y == 0 && labyrinth->end.y == gameFieldSize.y)
            {
                this->displayUpdated();
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        case DISPPART:
        {
            if(labyrinth->start.x == 0 && labyrinth->end.x == gameFieldSize.x && labyrinth->start.y == 0 && labyrinth->end.y == gameFieldSize.y)
            {
                this->displayFull();
            }
            else
            {
                this->displayPartialy();
            }
            break;
        }
        default:
        {
            this->displayPartialy();
        }
    }
}

/**
 * @brief   redraw every Point of the labyrinth
 */
void DisplayHandler::displayFull()
{
    for(int j = 0; j < gameFieldSize.y; j++)
    {
        mvaddstr(j, 0, labyrinth->labyrinth[j]);
    }
    this->prevDisplayMethod = DISPFULL;
}

/**
 * @brief   display labyrinth partialy, using the start and end Points
 */
void DisplayHandler::displayPartialy()
{
    clear();
    for(int j = labyrinth->start.y; j < labyrinth->end.y; j++)
    {
        move(j - labyrinth->start.y, 0);
        for(int i = labyrinth->start.x; i < labyrinth->end.x; i++)
        {
            addch(labyrinth->labyrinth[j][i]);
        }
    }
    this->prevDisplayMethod = DISPPART;
}

/**
 * @brief   draw only the changed Points when the labyrinth is being fully displayed
 */
void DisplayHandler::displayUpdated()
{
    std::deque<Point> cpChange;

    Point tmp;
    labyrinth->change.getRmQueue(&cpChange);
    for(auto it = cpChange.begin(); it != cpChange.end(); ++it)
    {
        tmp = *it;
        mvaddch(tmp.y, tmp.x, ' ');
    }
    labyrinth->change.getAddQueue(&cpChange);
    for(auto it = cpChange.begin(); it != cpChange.end(); ++it)
    {
        tmp = *it;
        mvaddch(tmp.y, tmp.x, tmp.style.letter);
    }

    this->prevDisplayMethod = DISPUPD;
}
