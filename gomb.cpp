#include "Gomb.hpp"
#include "graphics.hpp"

using namespace genv;


Gomb::Gomb( int _x, int _y, int _size_x, int _size_y, std::string _szoveg)
    : Widget( _x, _y, _size_x, _size_y ), szoveg(_szoveg)
{
    checked = false;
}

void Gomb::draw()
{
    gout<<move_to(x, y)<<color(254,253,114)<<box(size_x, size_y);
    if ( checked ) {
        gout << color(214,210,84);
        gout << move_to(x, y) << box(size_x, size_y);
    }
    gout<<move_to(x+size_x/2-gout.twidth(szoveg)/2,y+size_y/2+gout.cdescent())<<color(0,0,0)<<text(szoveg);
}

void Gomb::handle(event ev)
{
}

bool Gomb::is_checked() const
{
    return checked;
}
