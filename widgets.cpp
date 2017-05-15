#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;

Widget::Widget( ) {}
Widget::Widget( int _x, int _y ) : x(_x), y(_y) {}
Widget::Widget( int _x, int _y, int _size_x, int _size_y )
{
    x = _x;
    y = _y;
    size_x = _size_x;
    size_y = _size_y;
}

bool Widget::is_selected( int mouse_x, int mouse_y ) const
{
    return mouse_x>x && mouse_x<x+size_x && mouse_y>y && mouse_y<y+size_y;
}

void Widget::draw() {}

void Widget::handle(event ev) {}
