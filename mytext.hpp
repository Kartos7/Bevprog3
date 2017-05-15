#ifndef MyText_hpp_included
#define MyText_hpp_included

#include "graphics.hpp"
#include "widgets.hpp"

class MyText : public Widget
{
protected:
    std::string lab;
    std::string s;
    genv::color c1;
    genv::color c2;

public:
    MyText(int _x, int _y, genv::color _c1, genv::color _c2);
    MyText(int _x, int _y, std::string _lab, genv::color _c1, genv::color _c2);

    virtual void draw();
};

#endif // mytex_hpp_included
