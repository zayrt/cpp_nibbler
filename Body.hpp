//
// Body.hpp for body in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:23:27 2014 ilyas zelloufi
// Last update Mon Jul  7 12:23:29 2014 ilyas zelloufi
//

#ifndef  BODY_HPP_
# define BODY_HPP_

# include <iostream>
# include <vector>

typedef	struct	s_coord
{
  int	x;
  int	y;
}		t_coord;

class	Body
{

public:
  int	_x;
  int	_y;
public:
  Body(int const &, int const &);
  Body();
  ~Body();
  int	getX() const;
  int	getY() const;
};

#endif
