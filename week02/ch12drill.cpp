/* g++ ch12drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch `fltk-config --ldflags --use-images`*/ 

#include "Simple_window.h"
#include "Graph.h"


int main ()
{
    using namespace Graph_lib;
    
    Point tl {100,100};
    Simple_window win {tl,600,400,"My Window"}; //lesz egy ablakom ami 600*400pixel és My Window felirat lesz felül
    
    Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"}; // létrehozok egy x tengelyt ami a 20*300as pixelben kezdődik ,280px hosszu és beosztások vannak rajta,esetünkben 10, x axis felirattal
    Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};//ua ynal
    Function sine {sin,0,100,Point{20,150},1000,50,50};//sin görbét rajzol
    Polygon poly;//össze köt annyi pontot amennyit megadunk neki 
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    Rectangle r {Point{200,200}, 100, 50};//téglalapot rajzol aminek a felső bal sarka a 200*200as px és 100*50es
    Text t {Point{150,150}, "Hello, graphical world!"};//kiirja a szöveget
    Image ii {Point{10,10},"badge.jpg"};
    Circle c {Point{100,200},50};
    
    c.set_fill_color(Color::red); //kitölt pirossal
    sine.set_style(Line_style(Line_style::dash,3)); //szaggatott vastag vonal
    r.set_color(Color::dark_green);
    poly.set_style(Line_style::dash);
    t.set_font_size(25);
   
    
    win.attach(ii);
    win.attach(xa); //kirajzol
    win.attach(ya);
    win.attach(sine);
    win.attach(poly);
    win.attach(r);
    win.attach(t);
    win.attach(c);
    
    win.wait_for_button();
    
}
