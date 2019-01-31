#include <cstring>
#include <vector>

/**
 * Class of the giant snoke logo
 * @prop {int}                     x           - x coordinate of left logo side
 * @prop {int}                     y           - y coordinate of top logo side
 * @prop {PointStyle}              style       - style of the cells with logo
 * @prop {PointStyle}              shadowStyle - style of the cells with shadow of the logo
 * @prop {short}                   language    - language of the inscription at the logo, 0 - en, 1 - ru
 * @prop {map<short, const char*>} inscription - dictionary with translations for inscription
 */
class Logo
{
    private:
        int x, y;
        PointStyle style, shadowStyle;
        short language;
        std::vector<std::vector<const char*>> inscription;

    public:
        void draw();
        void setPosition(int x, int y);
        Point getSize();
        Logo(int x, int y, PointStyle style, PointStyle shadowStyle, int language);
};

#include "logo.cpp"
