#ifndef Button_HPP_INCLUDED
#define Button_HPP_INCLUDED

#include "widgets.hpp"
#include "graphics.hpp"

class Button : public Widget
{
protected:
    bool checked;
    bool push;
    bool sel;
    genv::color cbg;
    genv::color clc;
    genv::color clickc;

public:
    Button( int _x, int _y, int _size_x, int _size_y, genv::color cbg, genv::color clc, genv::color clickc);

    virtual void draw();
    virtual void handle( genv::event ev );

    virtual bool is_checked() const;

    virtual void set_cbg(int _r, int _g, int _b);
    virtual void set_clc(int _r, int _g, int _b);
    virtual void set_clickc(int _r, int _g, int _b);

    virtual int get_g() const;

    virtual bool get_push();
    virtual void set_push(bool _push);
};

#endif // Button_HPP_INCLUDED
