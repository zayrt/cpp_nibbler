//
// Xlib.hpp for Xlib in /home/zellou_i/rendu/cpp_nibbler/xlib
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Thu Apr  3 21:58:59 2014 ilyas zelloufi
// Last update Sun Apr  6 14:10:35 2014 Jean Luc TANG
//

#ifndef		XLIB_HPP_
# define	XLIB_HPP_

#include 	<X11/Xlib.h>
#include	<X11/keysym.h>
#include	"IGraphic.hpp"

class 		Xlib : public IGraphic
{
  Display	*d;
  Window	w;
  int		s;
  int   _height;
  int   _width;

public:
  Xlib(int const &, int const &);
  virtual	~Xlib();
  void    DrawWall(int const &, int const &);
  virtual void	putFood(t_coord const &, int const &) const;
  virtual way_t	getKey() const;
  virtual void	deleteBack(int const &, int const &) const;
  virtual void	moveBody(int const &, int const &) const;
};

#endif
