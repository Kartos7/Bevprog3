#ifndef Application_hpp_included
#define Application_hpp_included

#include "graphics.hpp"
#include "gomb.hpp"
#include "mytext.hpp"

using namespace genv;

class Application {
protected:
    int SX;
    int SY;
    int GAMe;     ///mekkora a tábla
    int point;

    std::string p1name;
    std::string p2name;

public:
    Application(int _SX, int _SY, int _GAMe);
    void start();
    void run();
};

#endif // Command_hpp_included

