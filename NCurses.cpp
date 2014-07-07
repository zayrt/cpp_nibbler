//
// Ncurses.cpp for nibbler in /home/tang_j/rendu/cpp_nibbler
// 
// Made by Jean Luc TANG
// Login   <tang_j@epitech.net>
// 
// Started on  Tue Apr  1 23:29:45 2014 Jean Luc TANG
// Last update Sun Apr  6 23:06:06 2014 Jean Luc TANG
//

#include "NCurses.hpp"
#include "Exception.hpp"
#include <stdlib.h>

NCurses::NCurses(int const &width, int const &height)
{
  int	x;
  int	y;

  try {
    if (initscr() != stdscr || start_color() == ERR || nodelay(stdscr, true) ==  ERR
	|| keypad(stdscr, true) == ERR || noecho() == ERR || curs_set(0) == ERR)
      throw(Exception("init ncurses"));
    getmaxyx(stdscr, y, x);
    if (height + 1 >= y || width + 1 >= x)
      throw(Exception("size of the map too big"));
    this->_yScore = height + 1;
    if (init_pair(1, COLOR_WHITE, COLOR_WHITE) == ERR || init_pair(2, COLOR_GREEN, COLOR_GREEN) == ERR
	|| init_pair(3, COLOR_RED, COLOR_RED) == ERR ||  init_pair(4, COLOR_BLACK, COLOR_BLACK) == ERR
	|| init_pair(5, COLOR_WHITE, COLOR_BLACK) == ERR)
      throw(Exception("init color"));
    if (attrset(COLOR_PAIR(1)) == ERR)
      throw(Exception("set color"));
    for (int i = 0; i <= height; i++)
      if (move(i, 0) == ERR || addch('|') == ERR)
	throw(Exception("move/addch"));
    for (int i = 0; i <= height; i++)
      if (move(i, width) == ERR || addch('|') == ERR)
	throw(Exception("move/addch"));
    for (int i = 1; i < width; i++)
    if (move(height, i) == ERR || addch('-') == ERR)
      throw(Exception("move/addch"));
    for (int i = 1; i < width; i++)
      if (move(0, i) == ERR || addch('-') == ERR)
	throw(Exception("move/addch"));
    if (refresh() == ERR)
      throw(Exception("refresh"));
  }catch(Exception const &error){
    endwin();
    throw(error);}
}

NCurses::~NCurses()
{
  nodelay(stdscr, false);
  endwin();
}

void	NCurses::moveBody(int const &x, int const &y) const
{
  if (attrset(COLOR_PAIR(2)) == ERR)
    throw(Exception("set color"));
  if (move(y, x) == ERR || addch(' ') == ERR
      || refresh() == ERR)
    throw(Exception("move/addch"));
}

void	NCurses::putFood(t_coord const &coord, int const &score) const
{
 if (attrset(COLOR_PAIR(5)) == ERR)
    throw(Exception("set color"));
 if (move(this->_yScore, 0) == ERR || printw("Score: %d", score) == ERR)
    throw(Exception("move/addr"));
 if (attrset(COLOR_PAIR(3)) == ERR)
   throw(Exception("set color"));
 if (move(coord.y, coord.x) == ERR || addch(' ') == ERR
     || refresh() == ERR)
   throw(Exception("move/addch"));
}

way_t	NCurses::getKey() const
{
  int	key;
  
  key = getch();
  switch (key)
    {
    case KEY_LEFT:
      return (K_LEFT);
    case KEY_RIGHT:
      return (K_RIGHT);
    case 27:
      return (K_ESC);
    }
  return (K_ELSE);
}

void	NCurses::deleteBack(int const &x, int const &y) const
{
  if (attrset(COLOR_PAIR(4)) == ERR)
    throw(Exception("set color"));
  if (move(y, x) == ERR || addch(' ') == ERR || refresh() == ERR)
    throw(Exception("move/addch"));
}

extern	"C"
{
  IGraphic	*getGraph(int const width, int const height)
  {
    return (new NCurses(width, height));
  }
}
