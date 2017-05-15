#include "MyTextBox.hpp"
#include "graphics.hpp"
#include <sstream>
#include <iostream>
#include <string>

using namespace genv;
using namespace std;

MyTextBox::MyTextBox(int _x, int _y, int _n, genv::color _c1, string _szoveg)
    : Widget (_x, _y), n(_n), c1(_c1), szoveg(_szoveg)
{
    checked = false;
    size_x = n * gout.twidth(" ") + 4;
    size_y = gout.cdescent() + gout.cascent() + 4;
    cursor = false;
}

void MyTextBox::draw()
{
    gout<<move_to(x, y)<<color(255,255,255)<<box(size_x, size_y);
    gout << move_to(x + 2, y + 2)<<color(255,255,255)<<box(size_x - 4, size_y - 4);
    gout<<move_to(x + 4,y + size_y - 5)<<c1<<text(szoveg);

    if (cursor && szoveg.length() < n)
    {
        gout<<move_to(x + 4 + gout.twidth(szoveg), y + 4 + gout.cascent())<<line(gout.twidth(" "), 0);
    }
}


void MyTextBox::handle(event ev)
{
    if(ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' '))           checked = !checked;
    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) checked = !checked;

    if(ev.type == ev_key && (ev.keycode >= 32 && ev.keycode < 256) && gout.twidth(szoveg)<size_x-10)
    {
        std::stringstream ss;
        ss<<szoveg<<char(ev.keycode);
        getline(ss, szoveg);
    }

    if(ev.type == ev_key && ev.keycode == key_backspace)
    {
        std::stringstream ss;
        ss<<szoveg.substr(0, szoveg.length() - 1);
        getline(ss,szoveg);
    }

    gin.timer(200);
    if (ev.type == ev_timer)  cursor = !cursor;
}

bool MyTextBox::is_checked()
{
    return checked;
}

void MyTextBox::set_szoveg(string s)
{
    szoveg = s;
}

string MyTextBox::get_szoveg() const
{
    return szoveg;
}
