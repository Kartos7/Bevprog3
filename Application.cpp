///Kálmán Zsolt - V00JVG ///
#include "Application.hpp"
#include "graphics.hpp"
#include "Button.hpp"
#include "MyTextBox.hpp"
//#include "Motor.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace genv;
using namespace std;

void kepbeolvas(canvas &kep, string kepnev, int &width, int &height)
 {

    unsigned short cr, cg, cb;

    ifstream bef(kepnev.c_str());
    bef>>width>>height;
    kep.open(width,height);

    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            bef>>cr>>cg>>cb;
            kep<<move_to(j,i)<<color(cr,cg,cb)<<dot;
        }
    }
}

Application::Application(int _SX, int _SY, int _GAMe): SX(_SX), SY(_SY), GAMe(_GAMe)
{
    p1name = "";
    p2name = "";
}

void Application::start()
{
    gout.open(SX,SY,true);
    gout.set_title("Amoba");

    vector<Widget*>w;       ///Menü widgetjei

    MyTextBox* MTB1 = new MyTextBox(600, 40, 20, color(70,130,180), "Player 1");
    w.push_back(MTB1);
    MyTextBox* MTB2 = new MyTextBox(600, 100, 20, color(254,253,114), "Player 2");
    w.push_back(MTB2);

    Gomb* G1 = new Gomb(50, 40, 70, 20, "Start");
    w.push_back(G1);
    Gomb* G2 = new Gomb(600, 550, 70, 20, "Exit");
    w.push_back(G2);

    canvas start;
    string logo = "maxresdefault.bmp.kep";
    int logo_w, logo_h;
    kepbeolvas(start, logo, logo_w, logo_h);

    event ev;
    int focus = -1;
    GAMe = 0;
    while(GAMe == 0 && gin >> ev)
    {
        if( ev.type == ev_mouse && ev.button==btn_left )
        {
            focus = -1;
            for( size_t i=0; i<w.size(); i++ )
            {
                if( w[i]->is_selected(ev.pos_x, ev.pos_y) )
                {
                    focus = i;
                }
            }
        }

        if( focus != -1 )
        {
            w[focus]->handle(ev);
        }

        gout<<stamp(start,0,0);



        gout<<color(255,255,255)<<move_to(600, 30)<<text("Sárga játékos neve:");
        gout<<move_to(600, 90)<<text("Piros játékos neve:");
        for( size_t i=0; i<w.size(); i++)
        {
            w[i]->draw();
        }

        p1name = MTB1->get_szoveg() + ":";
        p2name = MTB2->get_szoveg() + ":";

        if (G1->is_selected(ev.pos_x, ev.pos_y))
        {
            gin.timer(0);
            MyText* t4 = new MyText(50, 60, "", color(0,0,0), color(254,253,114));
            w.push_back(t4);
            w[w.size()-1]->handle(ev);
            w[w.size()-1]->draw();
            if (ev.button == -btn_left)
            {
                GAMe = 20;
                run();
            }
            w.erase(w.end()-1);
        }

        if ((G2->is_selected(ev.pos_x, ev.pos_y) && ev.button == -btn_left) || ev.keycode == key_escape)      GAMe = -1;

        gout << refresh;
    }
}

void Application::run()
{
    gin.timer(100);

    canvas bcg;
    string bcgs = "maxresdefault.bmp.kep";
    int bcg_w, bcg_h;
    kepbeolvas(bcg, bcgs, bcg_w, bcg_h);

    vector< vector<Button*> > t;
    int Column = 100;
    for (size_t i = 0; i < GAMe; i++)
    {
        vector<Button*> row;        ///palya generalas
        int Line = 200;
        for (size_t j = 0; j < GAMe; j++)
        {
            Button* b = new Button(Line, Column, 20, 20, color(154,254,116), color(111,211,77), color(72,183,29));
            row.push_back(b);
            Line+= 20;
        }
        Column+= 20;
        t.push_back(row);
    }

    vector< vector<int> > v;        ///palya mogott futo ket d-s tomb

    for (size_t i = 0; i <= GAMe +1; i++)
    {
        vector<int>row;
        for (size_t j = 0; j <= GAMe+ 1; j++)
        {
            if (j == GAMe + 1 || j == 0 || i == GAMe + 1 || i == 0)
            {
                row.push_back(point);
            }
            else    row.push_back(0);
        }
        v.push_back(row);
    }


    event ev;
    bool player = true;

    while(gin >> ev && GAMe != 0)
    {
        gin.timer(0);
        gout<<stamp(bcg,0,0);

        gout<<move_to(380, 20)<<color(154,254,116)<<text("Ha vissza akar jutni a fömenübe nyomjon Escape-t!");

        gout<<move_to(60,60)<<color(255,255,255)<<text(p1name);
        gout<<move_to(5,47)<<color(254,253,114)<<box(40,15);
        if (player)
        {
            gout<<move_to(6,48)<<color(255,255,255)<<line_to(44,62);      ///melyik player lep.
            gout<<move_to(44,48)<<line_to(6,62);
        }

        ///player2 pontok
        gout<<move_to(60,100)<<color(255,255,255)<<text(p2name);
        gout<<move_to(5,87)<<color(255,99,71)<<box(40,15);    ///sima
        if (!player)
        {
            gout<<move_to(6,88)<<color(255,255,255)<<line_to(44,102);      ///ha ez jön
            gout<<move_to(44,88)<<line_to(6,102);
        }
        for (size_t i = 0; i < GAMe; i++)
        {
            for (size_t j = 0; j < GAMe; j++)
            {
                t[i][j]->handle(ev);
                t[i][j]->draw();
            }
        }
        ///megnyomtam
        for (size_t i = 0; i < GAMe; i++)
        {
            for (size_t j = 0; j < GAMe; j++)
            {
                if (t[i][j]->is_selected(ev.pos_x, ev.pos_y) && ev.button == -btn_left && t[i][j]->get_push())
                {
                    if (player == 1)        ///különbözo szinu kockak kulonbozo szinei
                    {
                        t[i][j]->set_cbg(254,253,114);  ///piros
                    }

                    if (player == 0)
                    {
                        t[i][j]->set_cbg(255,99,71); ///sárga
                    }
                    player = !player;
                }
            }
            if (ev.keycode == key_escape)       ///kilepes
            {
                gin.timer(100);
                GAMe = 0;
            }

            gout<<refresh;
        }
    }
}

