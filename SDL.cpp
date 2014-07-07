//
// SDL.cpp for sdl in /home/benkha_z/Downloads/cpp_nibbler
// 
// Made by zakaria benkhalifa
// Login   <benkha_z@epitech.net>
// 
// Started on  Thu Apr  3 18:45:16 2014 zakaria benkhalifa
// Last update Sun Apr  6 19:10:54 2014 Jean Luc TANG
//

#include "SDL.hpp"
#include "Exception.hpp"

SDL::SDL(int const &width, int const &height)
{
  this->screen = NULL;
  this->head = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  this->food = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  this->init = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  this->wall = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  if (this->init == NULL || this->head == NULL || this->food == NULL || this->wall == NULL)
    throw(Exception("Create color surfaces"));
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw(Exception("Video Initialization"));

  const SDL_VideoInfo *screenMaxSize;
  int	maxX;
  int	maxY;
  screenMaxSize = SDL_GetVideoInfo();
  maxX = screenMaxSize->current_w;
  maxY = screenMaxSize->current_h;
  if (width * 10 >= maxX || maxY <= height * 10 + 50)
    throw(Exception("Size of map too big"));

  if ((this->screen = SDL_SetVideoMode((width * 10) + 10, (height * 10) + 10, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    throw(Exception("Video settings"));
  SDL_WM_SetCaption("Snake", NULL);
  this->color_back = SDL_MapRGB(this->screen->format, 232, 202, 111);
  if ((SDL_FillRect(this->screen, NULL, this->color_back)) == -1 ||
      (SDL_FillRect(this->init, NULL, this->color_back)) == -1 ||
      (SDL_FillRect(this->head, NULL, SDL_MapRGB(this->screen->format, 44, 150, 81))) == -1 ||
      (SDL_FillRect(this->food, NULL, SDL_MapRGB(this->screen->format, 224, 22, 36))) == -1 ||
      (SDL_FillRect(this->wall, NULL, SDL_MapRGB(this->screen->format, 22, 13, 0))) == -1 ||
      (SDL_Flip(this->screen)) == -1)
    throw(Exception("Window packing"));
  this->drawWall(width, height);
}

SDL::~SDL()
{
  SDL_FreeSurface(head);
  SDL_FreeSurface(food);
  SDL_FreeSurface(init);
  SDL_FreeSurface(wall);
  SDL_FreeSurface(screen);
  SDL_Quit();
}

void	SDL::putFood(t_coord const &coord, int const &score) const
{
  SDL_Rect	position;

  std::cout << "Score : "<< score << std::endl;
  position.x = coord.x * 10;
  position.y = coord.y * 10;
  if((SDL_BlitSurface(this->food, NULL, this->screen, &position)) == -1 ||
     (SDL_Flip(this->screen)) == -1)
    throw(Exception("Window packing"));
}

void	SDL::drawWall(int const &width, int const &height)
{
  SDL_Rect	position;

  for (int x = 0; x <= width; x++) {
    position.x = x * 10;
    position.y = height * 10;
    SDL_BlitSurface(this->wall, NULL, this->screen, &position);
  }
  for (int x = 0; x <= width; x++) {
    position.x = x * 10;
    position.y = 0;
    SDL_BlitSurface(this->wall, NULL, this->screen, &position);
  }
  for (int y = 0; y <= height; y++) {
    position.y = y * 10;
    position.x = 0;
    SDL_BlitSurface(this->wall, NULL, this->screen, &position);
  }
  for (int y = 0; y <= height; y++) {
    position.y = y * 10;
    position.x = width * 10;
    SDL_BlitSurface(this->wall, NULL, this->screen, &position);
  }
}

way_t	SDL::getKey() const
{
  SDL_Event	event;

  while(SDL_PollEvent(&event))
    {
      if (event.type == SDL_KEYDOWN)
	switch (event.key.keysym.sym)
	  {
	  case SDLK_LEFT:
	    return (K_LEFT);
	  case SDLK_RIGHT:
	    return (K_RIGHT);
	  case SDLK_ESCAPE:
	  return (K_ESC);
	  default:
	    break;
	  }
    }
  return (K_ELSE);
}

void	SDL::deleteBack(int const &x, int const &y) const
{
  SDL_Rect	position;

  position.x = x * 10;
  position.y = y * 10;
  if ((SDL_BlitSurface(this->init, NULL, this->screen, &position)) == -1 ||
    (SDL_Flip(this->screen)) == -1)
    throw(Exception("Window packing"));
}

void	SDL::moveBody(int const &x, int const &y) const
{
  SDL_Rect	position;

  position.x = x * 10;
  position.y = y * 10;
  if ((SDL_BlitSurface(this->head, NULL, this->screen, &position)) == -1 ||
    (SDL_Flip(this->screen)) == -1)
    throw(Exception("Window packing"));
}

extern	"C"
{
  IGraphic	*getGraph(int const width, int const height)
  {
    return (new SDL(width, height));
  }
}
