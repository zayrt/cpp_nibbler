//
// test.cpp for test in /home/zellou_i
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Thu Apr  3 21:18:09 2014 ilyas zelloufi
// Last update Sun Apr  6 23:04:29 2014 Jean Luc TANG
//

#include "Xlib.hpp"
#include "Exception.hpp"
#include <sstream>

Xlib::Xlib(int const &width, int const &height)
{
  int	max_width;
  int	max_height;

  if ((this->d = XOpenDisplay(NULL)) == NULL)
      throw(Exception("XOpenDisplay() fail."));
  this->s = DefaultScreen(this->d);
  max_width = DisplayWidth(this->d, this->s);
  max_height = DisplayHeight(this->d,this->s);
  this->_height = height * 10;
  this->_width = width * 10;
  if (max_width <= width * 10 || max_height <= height * 10 + 60)
      throw(Exception("Size of the map too big"));
  this->w = XCreateSimpleWindow(this->d, RootWindow(this->d, this->s), 0, 0, width * 10 + 10, height * 10 + 20, 0, WhitePixel(this->d, this->s), BlackPixel(this->d, this->s));
  XSelectInput(this->d, this->w, KeyPressMask | StructureNotifyMask);
  XStoreName (this->d, this->w, "Xlib");
  XMapWindow(this->d, this->w);
  XEvent e;
  while (42) {
    XNextEvent(this->d, &e);
    if (e.type == MapNotify)
      break;
  }
  this->DrawWall(width, height);
}
Xlib::~Xlib()
{
  XDestroyWindow(this->d, this->w);
  XCloseDisplay(this->d);
}

void  Xlib::DrawWall(int const &width, int const &height)
{
  char blue[] = "#00FFFF";
  GC blue_gc;
  XColor blue_col;
  Colormap colormap;

  colormap = DefaultColormap(this->d, 0);
  blue_gc = XCreateGC(this->d, this->w, 0, 0);
  XParseColor(this->d, colormap, blue, &blue_col);
  XAllocColor(this->d, colormap, &blue_col);
  XSetForeground(this->d, blue_gc, blue_col.pixel);
  for (int x = 0; x <= width; x++) {
    XSetForeground(this->d, blue_gc, blue_col.pixel);
    XFillRectangle(this->d, this->w, blue_gc, 10 * x, height * 10, 10, 10);
  }
  for (int x = 0; x < width; x++) {
    XSetForeground(this->d, blue_gc, blue_col.pixel);
    XFillRectangle(this->d, this->w, blue_gc, 10 * x, 0, 10, 10);
  } 
  for (int y = 0; y < height; y++) {
    XSetForeground(this->d, blue_gc, blue_col.pixel);
    XFillRectangle(this->d, this->w, blue_gc, 0, 10 * y, 10, 10);
  }
  for (int y = 0; y <= height; y++) {
    XSetForeground(this->d, blue_gc, blue_col.pixel);
    XFillRectangle(this->d, this->w, blue_gc, width * 10, 10 * y, 10, 10);
  }
}

void  Xlib::putFood(t_coord const &coord, int const &score) const
{
  char orange[] = "#FF3300";
  GC orange_gc;
  GC white_gc;
  XColor orange_col;
  Colormap colormap;
  std::ostringstream oss;
  int whiteColor = WhitePixel(this->d, this->s);
  oss << score;
  std::string result = oss.str();
  result = "Score : " + result;
  colormap = DefaultColormap(this->d, 0);

  orange_gc = XCreateGC(this->d, this->w, 0, 0);
  white_gc = XCreateGC(this->d, this->w, 0, 0);
  XParseColor(this->d, colormap, orange, &orange_col);
  XAllocColor(this->d, colormap, &orange_col);
  XSetForeground(this->d, orange_gc, orange_col.pixel);
  XFillRectangle(this->d, this->w, orange_gc, 10 * coord.x, 10 * coord.y, 10, 10);
  for (int x = 0; x <= this->_width + 10; x += 10) {
    XFillRectangle(this->d, this->w, DefaultGC(this->d, this->s),  x, this->_height + 10, 10, 10);
  }
  XSetForeground(this->d, white_gc, whiteColor);
  XDrawString(this->d, this->w, white_gc, 10 , this->_height + 19, result.c_str(), result.length());
}

way_t Xlib::getKey() const
{
   XEvent e;

   if (XPending(this->d) > 0) {
     XNextEvent(this->d, &e);
     if (e.type == KeyPress)
        {
          while (XPending(this->d) > 0)
            XNextEvent(this->d, &e);
          switch (XLookupKeysym(&e.xkey, 0))
          {
            case XK_Escape:
              return (K_ESC);
            case XK_Left:
              return (K_LEFT);
            case XK_Right:
              return (K_RIGHT);
          }
        }
    }
  return (K_ELSE);
}

void  Xlib::deleteBack(int const &x, int const &y) const
{
  XFillRectangle(this->d, this->w, DefaultGC(this->d, this->s), 10 * x, 10 * y, 10, 10);
}

void  Xlib::moveBody(int const &x, int const &y) const
{
  char green[] = "#33FF33";
  GC green_gc;
  XColor green_col;
  Colormap colormap;

  colormap = DefaultColormap(this->d, 0);
  green_gc = XCreateGC(this->d, this->w, 0, 0);
  XParseColor(this->d, colormap, green, &green_col);
  XAllocColor(this->d, colormap, &green_col);
  XSetForeground(this->d, green_gc, green_col.pixel);
  XFillRectangle(this->d, this->w, green_gc, 10 * x, 10 * y, 10, 10);
}

extern  "C"
{
  IGraphic  *getGraph(int const width, int const height)
  {
    return (new Xlib(width, height));
  }
}
