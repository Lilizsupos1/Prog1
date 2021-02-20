/* g++ ex12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex `fltk-config --ldflags --use-images`*/ 

#include "Simple_window.h"
#include "Graph.h"

int main ()
{
     using namespace Graph_lib;
    
     Point tl {100,100};
     Simple_window win {tl,1200,800,"My Window"};
     
     int win_szel=1200;
     int win_mag=800;
     int inch=96;
     
     Rectangle r{Point{200,200},100,50};
     r.set_color(Color::blue);
     Polygon poly;
     poly.add(Point{100,50});
     poly.add(Point{200,50});
     poly.add(Point{200,100});
     poly.add(Point{100,100});
     poly.set_color(Color::red);
     Rectangle r2{Point{300,250},100,30};
     Text t {Point{325,275},"Howdy!"};
     Text zs {Point{300,150},"Zs"};
     zs.set_font_size(150);
     zs.set_font(Font::times_bold);
     zs.set_color(Color::green);
     Text l {Point{475,150},"L"};
     l.set_font_size(150);
     l.set_font(Font::times_bold);
     l.set_color(Color::blue);
     Rectangle sakk1{Point{500,500},50,50};
     sakk1.set_fill_color(Color::red);
     Rectangle sakk2{Point{500,550},50,50};
     sakk2.set_fill_color(Color::white);
     Rectangle sakk3{Point{500,600},50,50};
     sakk3.set_fill_color(Color::red);
     Rectangle sakk4{Point{550,500},50,50};
     sakk4.set_fill_color(Color::white);
     Rectangle sakk5{Point{550,550},50,50};
     sakk5.set_fill_color(Color::red);
     Rectangle sakk6{Point{550,600},50,50};
     sakk6.set_fill_color(Color::white);
     Rectangle sakk7{Point{600,500},50,50};
     sakk7.set_fill_color(Color::red);
     Rectangle sakk8{Point{600,550},50,50};
     sakk8.set_fill_color(Color::white);
     Rectangle sakk9{Point{600,600},50,50};
     sakk9.set_fill_color(Color::red);
     Rectangle r3{Point{50,50},win_szel/3*2,win_mag/4*3};
     r3.set_style(inch/3);
     Rectangle haz{Point{500,250},200,200};
     Rectangle ajto{Point{600,350},50,100};
     Polygon teto;
     teto.add(Point{600,150});
     teto.add(Point{500,250});
     teto.add(Point{700,250});
     Rectangle ablak1{Point{550,300},25,25};
     Rectangle ablak2{Point{600,300},25,25};
     Rectangle kemeny{Point{525,200},15,40};
     Circle olimpia1 {Point{100,450},50};
     olimpia1.set_color(Color::blue);
     Circle olimpia2 {Point{210,450},50};
     olimpia2.set_color(Color::black);
     Circle olimpia3{Point{320,450},50};
     olimpia3.set_color(Color::red);
     Circle olimpia4{Point{155,500},50};
     olimpia4.set_color(Color::yellow);
     Circle olimpia5{Point{275,500},50};
     olimpia5.set_color(Color::green);
     Image ii {Point{750,10},"badge.jpg"};
     Text kepal{Point{850,450},"Diploma"};
     
     
     Simple_window win2 {tl,4000,2000,"Window2"};
     Rectangle r4{Point{10,10},4050,2050};
     
     
    win.attach(ii); 
    win.attach(r3);
    win.attach(r);
    win.attach(poly);
    win.attach(r2);
    win.attach(t);
    win.attach(zs);
    win.attach(l);
    win.attach(sakk1);
    win.attach(sakk2);
    win.attach(sakk3);
    win.attach(sakk4);
    win.attach(sakk5);
    win.attach(sakk6);
    win.attach(sakk7);
    win.attach(sakk8);
    win.attach(sakk9);
    //win2.attach(r4);
    win.attach(haz);
    win.attach(ajto);
    win.attach(teto);
    win.attach(ablak1);
    win.attach(ablak2);
    win.attach(kemeny);
    win.attach(olimpia1);
    win.attach(olimpia2);
    win.attach(olimpia3);
    win.attach(olimpia4);
    win.attach(olimpia5);
    win.set_label("Diploma");
    win.attach(kepal);
    
    win.wait_for_button();
    //win2.wait_for_button();
}


