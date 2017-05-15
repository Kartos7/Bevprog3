#include "Button.hpp"
#include "graphics.hpp"
#include <sstream>
#include <iostream>

using namespace genv;

Button::Button( int _x, int _y, int _size_x, int _size_y, color _cbg, color _clc, color _clickc)
    : Widget( _x, _y, _size_x, _size_y ), cbg(_cbg), clc(_clc), clickc(_clickc)
{
    checked = false;
    sel = false;
    push = false;
}

void Button::draw()
{
    gout<<move_to(x-2,y-2)<<color(0,0,0)<<box(size_x+4,size_y+4);
    gout<<move_to(x, y)<<cbg<<box(size_x, size_y);

    if ( checked )
    {
        gout << clickc;
        gout << move_to(x, y) << box(size_x, size_y);
    }

    if (sel && checked == false)
    {
        gout << clc;
        gout << move_to(x, y) << box(size_x, size_y);
        sel = false;
    }
}

void Button::handle(event ev)
{
    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y))
    {
        sel = true;
        if (ev.button==btn_left)
        {
            checked = true;
            gin.timer(100);
            push = true;
        }
        if (ev.button == -btn_left)
        {
            checked = false;
            gin.timer(100);
        }
    }
    else if (ev.type == ev_mouse) checked = false;
}

bool Button::is_checked() const
{
    return checked;
}
void Button::set_cbg(int _r, int _g, int _b)
{
    cbg.red = _r;
    cbg.green = _g;
    cbg.blue = _b;
}

int Button::get_g() const
{
    return cbg.red;
}

void Button::set_clc(int _r, int _g, int _b)
{
    clc.red = _r;
    clc.green = _g;
    clc.blue = _b;
}

void Button::set_clickc(int _r, int _g, int _b)
{
    clickc.red = _r;
    clickc.green = _g;
    clickc.blue = _b;
}

bool Button::get_push()
{
    return push;
}

void Button::set_push(bool _push)
{
    push = _push;
}
