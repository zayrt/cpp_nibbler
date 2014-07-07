//
// Food.cpp for food in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:24:10 2014 ilyas zelloufi
// Last update Mon Jul  7 12:24:11 2014 ilyas zelloufi
//

#include <cstdlib>
#include "Food.hpp"


Food::Food(std::vector<Body> const &snake, int const &width, int const &height)
{
  setNewFood(snake, width, height);
}

Food::~Food()
{

}

t_coord	Food::getCoord() const
{
  return (this->_coord);
}

void		Food::setNewFood(std::vector<Body> const &snake, int const &width, int const &height)
{
  int		x;
  int		y;
  unsigned int	i = 0;

  x = rand() % width;
  y = rand() % height;
  while (i < snake.size())
   {
     if ((snake[i].getX() == x && snake[i].getY() == y) || 
	  (x >= width || y >= height) || x == 0 || y == 0)
	{
	  this->setNewFood(snake, width, height);
	  break;
	}
     i++;
   }
  if (i == snake.size())
    {
      this->_coord.x = x;
      this->_coord.y = y;
    }
}
