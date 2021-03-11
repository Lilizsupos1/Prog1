/* g++ ex13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex `fltk-config --ldflags --use-images`*/ 




#include "Simple_window.h"
#include "Graph.h"
#include "fltk.h"
#include "std_lib_facilities.h"
#include <vector> 



#include<iostream>



//Class Arc
using namespace Graph_lib;
class Arc : public Shape {
public:
    Arc(Point p, int w, int h, double fok1, double fok2)    // center, min, and max distance from center
        : w(w), h(h) , f1(fok1), f2(fok2)
    { 
        add(Point(p.x-w,p.y-h));
    }

    void draw_lines() const {fl_arc(point(0).x,point(0).y,w+w,h+h,f1,f2);}

    Point center() const { return Point(point(0).x+w,point(0).y+h); }
    

    void set_major(int ww) { w=ww; }
    int major() const { return w; }
    void set_minor(int hh) { h=hh; }
    int minor() const { return h; }

private:
    int w;
    int h;
    double f1;
    double f2;
    
};




//Class Box


class Box: public Shape{
public: 
    Box(Point p, int w, int h,int r)
        : w(w), h(h) , r(r)
        {
            
            add(Point(p.x,p.y));
        }
    void draw_lines() const {fl_arc(point(0).x-r,point(0).y-r,r*2,r*2,90,180);
        fl_arc(point(0).x-r,point(0).y-r+h,r*2,r*2,180,270);
        fl_arc(point(0).x-r+w,point(0).y-r+h,r*2,r*2,270,360);
        fl_arc(point(0).x-r+w,point(0).y-r,r*2,r*2,0,90);
        fl_line(point(0).x,point(0).y-r,point(0).x+w,point(0).y-r);
        fl_line(point(0).x,point(0).y+h+r,point(0).x+w,point(0).y+h+r);
        fl_line(point(0).x-r,point(0).y,point(0).x-r,point(0).y+h);
        fl_line(point(0).x+r+w,point(0).y,point(0).x+r+w,point(0).y+h);
    }
    
    
    
private:
    int w;
    int h;
    int r;
};


//class Arrow


class Arrow:public Shape{
    
public:
    Arrow (Point p,Point p2,int pol)
    :  pol(pol)
    {
        add(Point(p.x,p.y));
        add(Point(p2.x,p2.y));
        
    }
    
    void draw_lines() const {fl_polygon(point(0).x,point(0).y,point(0).x-pol,point(0).y+pol,point(0).x+pol,point(0).y+pol);
        fl_line(point(0).x,point(0).y+pol,point(1).x,point(1).y);
       
    }
    
    
private:
    
    int pol;
    

    
    
};

/*
Point n (Circle& kor){
    return Point{kor.center().x,kor.center().y-kor.radius()};
}

Point nw (Circle& kor){
    return Point{kor.center().x-kor.radius(),kor.center().y-kor.radius()};
}
Point e (Circle& kor){
    return Point{kor.center().x+kor.radius(),kor.center().y};
}
Point se (Circle& kor){
    return Point{kor.center().x+kor.radius(),kor.center().y+kor.radius()};
}
Point s (Circle& kor){
    return Point{kor.center().x,kor.center().y+kor.radius()};
}
Point sw (Circle& kor){
    return Point{kor.center().x-kor.radius(),kor.center().y+kor.radius()};
}
Point w (Circle& kor){
    return Point{kor.center().x-kor.radius(),kor.center().y};
}
Point ne (Circle& kor){
    return Point{kor.center().x+kor.radius(),kor.center().y-kor.radius()};
}




Point se (Ellipse& eli){
    return Point{eli.center().x+eli.major(),eli.center().y+eli.minor()};
}

Point nw (Ellipse& eli){
    return Point{eli.center().x-eli.major(),eli.center().y-eli.minor()};
}
Point e (Ellipse& eli){
    return Point{eli.center().x+eli.major(),eli.center().y};
}
Point n (Ellipse& eli){
    return Point{eli.center().x,eli.center().y-eli.minor()};
}
Point s (Ellipse& eli){
    return Point{eli.center().x,eli.center().y+eli.minor()};
}
Point sw (Ellipse& eli){
    return Point{eli.center().x-eli.major(),eli.center().y+eli.minor()};
}
Point w (Ellipse& eli){
    return Point{eli.center().x-eli.major(),eli.center().y};
}
Point ne (Ellipse& eli){
    return Point{eli.center().x+eli.major(),eli.center().y-eli.minor()};
}

*/






int main()
{
    using namespace Graph_lib;

    Point t(100,100);
    Simple_window win(t,600,400, "Simple window");
    Arc a{Point{200,200},150,50,0,120};
    Box b{Point{40,40},50,60,10};
    Arrow arr{Point{150,300},Point{150,350},5};
    //Circle c{Point{200,50},40};
    //Ellipse ell{Point{400,100},70,50};
   
    //Mark m1{w(c),'x'};
    //Mark m2{ne(ell),'*'};
    
    
    
    
    Box window{Point{300,250},50,10,10};
    Text windowt{Point{301,252},"Window"};
    Arrow windowarr{Point{325,265},Point{325,275},3};
    Box line_style{Point{380,250},65,10,10};
    Text line_stylet{Point{381,252},"Line_style"};
    Box color{Point{490,250},50,10,10};
    Text colort{Point{491,252},"Color"};
    Box simple_window{Point{280,290},110,10,10};
    Text simple_windowt{Point{281,292},"Simple_window"};
    Box shape{Point{420,290},40,10,10};
    Text shapet{Point{421,292},"Shape"};
    Box point{Point{490,290},40,10,10};
    Text pointt{Point{491,292},"Point"};
    Box line{Point{180,350},40,10,10};
    Text linet{Point{181,352},"Line"};
    Arrow linearr{Point{420,300},Point{200,340},3};
    Box lines{Point{240,350},40,10,10};
    Text linest{Point{241,352},"Lines"};
    Arrow linesarr{Point{425,300},Point{260,340},3};
    Box polygon{Point{300,350},50,10,10};
    Text polygont{Point{301,352},"Polygon"};
    Arrow polygonarr{Point{430,300},Point{325,340},3};
    Box axis{Point{370,350},30,10,10};
    Text axist{Point{371,352},"Axis"};
    Arrow axisarr{Point{435,300},Point{385,340},3};
    Box rectangle{Point{420,350},60,10,10};
    Text rectanglet{Point{420,352},"Rectangle"};
    Arrow rectanglearr{Point{440,300},Point{450,340},3};
    Box text{Point{500,350},30,10,10};
    Text textt{Point{501,352},"Text"};
    Arrow textarr{Point{445,300},Point{515,340},3};
    Box image{Point{550,350},30,10,10};
    Text imaget{Point{550,352},"Image"};
    Arrow imagearr{Point{450,300},Point{565,340},3};
   
    
    Simple_window win2(t,600,400, "Simple window");
    Vector_ref<Rectangle> vr;
    for (int i = 0; i<16; ++i)
    for (int j = 0; j<16; ++j) {
    vr.push_back(new Rectangle{Point{i*20,j*20},20,20});
    vr[vr.size()-1].set_fill_color(Color{i*16+j});
    win2.attach(vr[vr.size()-1]);
    }
    
    
    //win.attach(c);
    win.attach(arr);
    win.attach(b);
    win.attach(a);
    //win.attach(m1);
    //win.attach(ell);
   // win.attach(m2);
    
    win.attach(window);
    win.attach(windowt);
    win.attach(line_style);
    win.attach(line_stylet);
    win.attach(color);
    win.attach(colort);
    win.attach(simple_window);
    win.attach(simple_windowt);
    win.attach(shape);
    win.attach(shapet);
    win.attach(point);
    win.attach(pointt);
    win.attach(line);
    win.attach(linet);
    win.attach(lines);
    win.attach(linest);
    win.attach(polygon);
    win.attach(polygont);
    win.attach(axis);
    win.attach(axist);
    win.attach(rectangle);
    win.attach(rectanglet);
    win.attach(text);
    win.attach(textt);
    win.attach(image);
    win.attach(imaget);
    win.attach(windowarr);
    win.attach(linearr);
    win.attach(linesarr);
    win.attach(polygonarr);
    win.attach(axisarr);
    win.attach(rectanglearr);
    win.attach(textarr);
    win.attach(imagearr);
 
    
    
    
    win.wait_for_button();
    win2.wait_for_button();
}
