void Navigator::pushUnit(Widget* unit, int subunitsAmount)
{
    units.push_back({unit, subunitsAmount});
}

void Navigator::listen()
{
    curs_set(0);
    noecho();
    currentUnit = units.begin();
    currentSubunit = 0;
    currentUnit->widget->focus(currentSubunit);

    while (1)
    {
        int command = getch();

        if (command != ERR)
        {
            switch(command)
            {
                case (119):

                    currentUnit->widget->unfocus(currentSubunit);
                    if (currentSubunit > 0)
                    {
                        currentSubunit--;
                    }
                    else if (currentUnit != units.begin())
                    {
                        currentUnit--;
                        currentSubunit = currentUnit->subunitsAmount - 1;
                    }
                    currentUnit->widget->focus(currentSubunit);
                    break;

                case (115):

                    currentUnit->widget->unfocus(currentSubunit);
                    if (currentSubunit < currentUnit->subunitsAmount - 1)
                    {
                        currentSubunit++;
                    }
                    else if (std::distance(units.begin(), currentUnit) + 1 < (unsigned int)units.size())
                    {
                        currentUnit++;
                        currentSubunit = 0;
                    }

                    move(0, 0);
                    currentUnit->widget->focus(currentSubunit);
                    break;
            }
        }
    }
}

Navigator::Navigator()
{
    currentUnit = units.begin();
    currentSubunit = 0;
}
