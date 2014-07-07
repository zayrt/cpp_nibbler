//
// Ncurses.hpp for nibbler in /home/tang_j/rendu/cpp_nibbler
// 
// Made by Jean Luc TANG
// Login   <tang_j@epitech.net>
// 
// Started on  Tue Apr  1 23:26:34 2014 Jean Luc TANG
// Last update Sun Apr  6 16:01:10 2014 Jean Luc TANG
//

#ifndef		NCURSES_HPP_
# define	NCURSES_HPP_

# include	<ncurses.h>
# include	<iostream>
# include	"IGraphic.hpp"

class		NCurses : public IGraphic
{
private:
  int		_yScore;

public:
  NCurses(int const &, int const &);
  virtual	~NCurses();
  virtual void	putFood(t_coord const &, int const &) const;
  virtual way_t	getKey() const;
  virtual void	deleteBack(int const &, int const &) const;
  virtual void	moveBody(int const &, int const &) const;
};

#endif
