//
// IGraphic.hpp for Igraphic in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:24:47 2014 ilyas zelloufi
// Last update Mon Jul  7 12:24:48 2014 ilyas zelloufi
//

#ifndef	 IGRAPHIC_HPP_
# define IGRAPHIC_HPP_

# include <iostream>
# include <vector>
# include "Body.hpp"

typedef enum	way_e
  {
    K_LEFT,
    K_RIGHT,
    K_ESC,
    K_ELSE
  }		way_t;

typedef enum	dire_e
  {
    UP,
    DOWN,
    LEFT,
    RIGHT
  }		dire_t;

class	IGraphic
{
public:
  virtual way_t	getKey() const = 0;
  virtual void	putFood(t_coord const &, int const &) const = 0;
  virtual void	deleteBack(int const &, int const &) const = 0;
  virtual void	moveBody(int const &, int const &) const = 0;
  virtual	~IGraphic() {}
};

#endif
