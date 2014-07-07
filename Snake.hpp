//
// Snake.hpp for snake in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:25:22 2014 ilyas zelloufi
// Last update Mon Jul  7 12:25:23 2014 ilyas zelloufi
//

#ifndef  SNAKE_HPP_
# define SNAKE_HPP_

# include <iostream>
# include <unistd.h>
# include <cstdlib>
# include <vector>
# include "Body.hpp"
# include "IGraphic.hpp"
# include "Food.hpp"

class			Snake
{
private:
  std::vector<Body>	_snake;
  int			_score;
  int			_speed;
  int			_width;
  int			_height;
  dire_t		_direction;
  bool			_getFood;

public:
  Snake(int const &, int const &);
  ~Snake();
  int	getScore();
  void	getDirection(way_t const &);
  bool	crash(t_coord const &);
  void	startSnake(IGraphic const *);
  void	addHead();
};

#endif
