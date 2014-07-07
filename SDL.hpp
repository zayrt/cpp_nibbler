//
// SDL.hpp for SDL in /home/benkha_z/Downloads/cpp_nibbler
// 
// Made by zakaria benkhalifa
// Login   <benkha_z@epitech.net>
// 
// Started on  Thu Apr  3 18:33:40 2014 zakaria benkhalifa
// Last update Sun Apr  6 18:40:10 2014 Jean Luc TANG
//

#ifndef		SDL_HPP_
# define	SDL_HPP_

# include <stdio.h>
# include <iostream>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include "IGraphic.hpp"

class		SDL : public IGraphic
{
private:
  SDL_Surface	*screen;
  SDL_Surface	*head;
  SDL_Surface	*food;
  SDL_Surface	*init;
  SDL_Surface	*wall;
  Uint32	color_back;

public:
  SDL(int const &, int const &);
  virtual	~SDL();
  void		drawRect(int, int, Uint32, int, int);
  void		drawWall(int const &width, int const &height);
  virtual void	putFood(t_coord const &, int const &) const;
  virtual way_t	getKey() const;
  virtual void	deleteBack(int const &, int const &) const;
  virtual void	moveBody(int const &, int const &) const;
};

#endif /* SDL_HPP_ */
