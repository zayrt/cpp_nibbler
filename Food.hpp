//
// Food.hpp for food in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:24:24 2014 ilyas zelloufi
// Last update Mon Jul  7 12:24:25 2014 ilyas zelloufi
//

#ifndef  FOOD_HPP_
# define FOOD_HPP_

# include <iostream>
# include "IGraphic.hpp"

class	Food
{
private:
  t_coord	_coord;
public:
  Food(std::vector<Body> const &, int const &, int const &);
  ~Food();
  t_coord	getCoord() const;
  void		setNewFood(std::vector<Body> const &, int const &, int const &);
};

#endif
