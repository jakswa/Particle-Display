#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include "myarea.h"
#include <iostream>

int main (int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  Gtk::Window win;
  win.set_border_width(10);
  win.set_default_size(500,400);
  win.set_title("Particle Display");
  Gtk::HBox hbox(false, 5);
  win.add(hbox);
  
  MyArea area;
  hbox.pack_start(area);
  area.show();
  
  Gtk::Button* pButton = new Gtk::Button("ooo");
  hbox.pack_start(*pButton, Gtk::PACK_SHRINK);
  (*pButton).show();
  hbox.show();
  Gtk::Main::run(win);

  return 0;
}
