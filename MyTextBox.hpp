#ifndef MyTextBox_hpp_included
#define MyTextBox_hpp_included

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>
#include "gomb.hpp"

class MyTextBox : public Widget
{
protected:
    bool cursor;
    bool checked;
    int n;
    std::string szoveg;
    genv::color c1;

public:
    MyTextBox(int _x, int _y, int _n, genv::color c1, std::string _szoveg);
    virtual void draw();
    virtual void handle(genv::event ev);

    virtual bool is_checked();
    virtual void set_szoveg(std::string s);
    virtual std::string get_szoveg() const;
};

#endif
