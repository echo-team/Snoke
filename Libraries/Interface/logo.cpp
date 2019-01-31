/**
 * Sets coordinates of logo
 * @param {int} left - x coordinate of left logo side
 * @param {int} top  - y coordinate of top logo side
 */
void Logo::setPosition(int left, int top)
{
    x = left;
    y = top;
}

/**
 * Returns size of the logo
 * @return {Point} - width and height of the logo
 */
Point Logo::getSize()
{
    Point size;
    size.x = strlen(inscription[language][0]);
    size.y = 5;

    return size;
}

/**
 * Draws Logo in console window
 */
void Logo::draw()
{
    init_color(COLOR_WHITE, 1000, 1000, 1000);
    init_pair(1, style.fg, style.bg);
    init_pair(2, shadowStyle.fg, shadowStyle.bg);

    for (int rowCounter = 0; rowCounter < 5; rowCounter++)
    {
        for (int colCounter = 0; colCounter < strlen(inscription[language][0]); colCounter++)
        {
            if (inscription[language][rowCounter][colCounter] != ' ')
            {
                move(y + rowCounter, x + colCounter);
                attron(COLOR_PAIR(1));
                addch(style.letter);
                attroff(COLOR_PAIR(1));

                attron(COLOR_PAIR(2));
                move(y + rowCounter + 1, x + colCounter + 1);
                addch(shadowStyle.letter);
                attroff(COLOR_PAIR(2));
            }
        }
    }
}

/**
 * @constructor
 * @param {PointStyle} style       - style of the cells with logo
 * @param {PointStyle} shadowStyle - style of the cells with shadow of the logo
 */
Logo::Logo(int x, int y, PointStyle style, PointStyle shadowStyle, int language) :
    x(x), y(y), style(style), shadowStyle(shadowStyle), language(language)
{
    inscription.push_back(
    {
        " **** *   *  ***  *   *  ****",
        "*     **  * *   * *   * *    ",
        " ***  * * * *   * ****   ****",
        "    * *  ** *   * *   * *    ",
        "****  *   *  ***  *   *  ****"
    });

    inscription.push_back(
        {
            "****  *   * *   *  *** ",
            "    * ** ** *  ** *   *",
            "  **  * * * * * * *   *",
            "    * *   * **  *  ****",
            "****  *   * *   * *   *"
        });
}
