//
// Body.cpp for nibbler in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:23:10 2014 ilyas zelloufi
// Last update Mon Jul  7 12:23:16 2014 ilyas zelloufi
//

#include "Body.hpp"

Body::Body(int const &x, int const &y)
{
  this->_x = x;
  this->_y = y;
}

Body::Body()
{
  this->_x = 0;
  this->_y = 0;
}

int	Body::getX() const
{
  return (this->_x);
}

int	Body::getY() const
{
  return (this->_y);
}

Body::~Body()
{

}
