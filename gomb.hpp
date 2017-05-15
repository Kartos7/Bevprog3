#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "mytext.hpp"

class Gomb : public Widget
{
protected:
    bool checked;
    std::string szoveg;

public:
    Gomb( int _x, int _y, int _size_x, int _size_y, std::string _szoveg);

    virtual void draw();
    virtual void handle( genv::event ev );

    virtual bool is_checked() const;
};

#endif


