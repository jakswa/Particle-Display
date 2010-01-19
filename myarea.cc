#include "myarea.h"
#include <cairomm/context.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>


MyArea::MyArea()
{
}

MyArea::~MyArea()
{
}

bool MyArea::on_expose_event(GdkEventExpose* event)
{
  // This is where we draw on the window
  Glib::RefPtr<Gdk::Window> window = get_window();
  if(window)
  {
    Gtk::Allocation allocation = get_allocation();
    const int width = 400;
    const int height = 400;
    
    //reading in points
    std::vector<double> coords;
    double coord;
    //coords.reserve(sizeof(coord) * 2000000);
    
    std::ifstream fin("ran.txt");
    if (fin.is_open()) {
        while(fin >> coord) {
            coords.push_back(coord);
        }
    } else {
        std::cout << "error opening file";
    }
    std::cout << "done. " << coords.size()/2 << " coords read.\n";
    
    

    Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();

    // clip to the area indicated by the expose event so that we only redraw
    // the portion of the window that needs to be redrawn
    cr->rectangle(event->area.x, event->area.y,
            event->area.width, event->area.height);
    cr->clip();

    // draw red lines out from the center of the window
    cr->set_source_rgb(0,0,0);
    cr->rectangle(0,0,width,height);
    cr->fill();
    cr->set_source_rgb(.5, .5, .5);
    std::cout << "about to draw.." << std::endl;
    for (std::vector<double>::const_iterator it = coords.begin(); it != coords.end() && it != coords.end()-1; it+=2) {
        cr->rectangle((int)(*it * width), (int)(*(it+1) * height), 1, 1);
    }
    std::cout << "here comes stroke" << std::endl;
    cr->stroke_preserve();
    cr->set_source_rgb(1,1,1);
    cr->fill();
  }

  return true;
}
void MyArea::displayPoints() {
}
