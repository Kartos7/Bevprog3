#include "MyText.hpp"
#include "graphics.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using namespace genv;

MyText::MyText(int _x, int _y, color _c1, color _c2)
    : Widget (_x, _y), c1(_c1), c2(_c2)

{
    size_x = 60 * gout.twidth(" ") + 6;
    size_y = 340;
    }

MyText::MyText(int _x, int _y, std::string _lab, color _c1, color _c2)
    : Widget (_x, _y), lab(_lab), c1(_c1), c2(_c2)

{
    if (lab.size() > 8)
    {
        size_x = gout.twidth(lab) + 6;
    }
    else    size_x = 60 * gout.twidth(" ") + 6;
    size_y = gout.cdescent() + gout.cascent() + 2;
}

void MyText::draw()
{
}
