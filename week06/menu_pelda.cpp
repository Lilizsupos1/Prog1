#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	
	

	bool wait_for_button();

private:
	Open_polyline lines;
	
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button menu_button;

	
	void hide_menu() {
		color_menu.hide();
		menu_button.show();
	}
	void menu_pressed() {
		menu_button.hide();
		color_menu.show();
	}
	
	
	void next();
	void quit();

	
};


Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},


    color_menu{ Point{x_max() - 70,60},70,20,Menu::vertical,"color" },

    
    menu_button{ Point{x_max() - 80,40},80,20, "color menu", [](Address, Address adr) {
    reference_to<Lines_window>(adr).color_menu.show();
  
    } }

{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    attach(lines);

    
    color_menu.attach(new Button{ Point{0,0},0,0,"red",[](Address, Address adr) {
        reference_to<Lines_window>(adr).lines.set_color(Color::red);  
        reference_to<Lines_window>(adr).hide_menu();
        reference_to<Lines_window>(adr).redraw();
        } });
    color_menu.attach(new Button{ Point{0,0},0,0,"blue",[](Address, Address adr) {
        reference_to<Lines_window>(adr).lines.set_color(Color::blue);
        reference_to<Lines_window>(adr).hide_menu();
        reference_to<Lines_window>(adr).redraw();
        } });
    color_menu.attach(new Button{ Point{0,0},0,0,"black",[](Address, Address adr) {
        reference_to<Lines_window>(adr).lines.set_color(Color::black);
        reference_to<Lines_window>(adr).hide_menu();
        reference_to<Lines_window>(adr).redraw();
        } });
   



    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
        
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}
