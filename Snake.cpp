//
// Snake.cpp for nibbler in /home/tang_j/rendu/cpp_nibbler
// 
// Made by Jean Luc TANG
// Login   <tang_j@epitech.net>
// 
// Started on  Tue Apr  1 01:24:48 2014 Jean Luc TANG
// Last update Sun Apr  6 19:43:44 2014 Jean Luc TANG
//

#include "Snake.hpp"

Snake::Snake(int const &width, int const &height)
{
  this->_score = 0;
  this->_width = width;
  this->_height = height;
  this->_speed = 110000;
  this->_direction = LEFT;
  this->_getFood = false;
  for (int i = 0; i <= 4; i++)
    this->_snake.push_back(Body(width / 2 + i, height / 2));
}

Snake::~Snake()
{

}

int	Snake::getScore()
{
  return (this->_score);
}

void	Snake::getDirection(way_t const &key)
{
  switch (this->_direction)
    {
    case LEFT:
      if (key == K_LEFT)
	this->_direction = DOWN;
      else if (key == K_RIGHT)
	this->_direction = UP;
      break;
    case RIGHT:
      if (key == K_LEFT)
	this->_direction = UP;
      else if (key == K_RIGHT)
	this->_direction = DOWN;
      break;
    case UP:
      if (key == K_LEFT)
	this->_direction = LEFT;
      else if (key == K_RIGHT)
	this->_direction = RIGHT;
      break;
    case DOWN:
      if (key == K_LEFT)
	this->_direction = RIGHT;
      else if (key == K_RIGHT)
	this->_direction = LEFT;
      break;
    }
}

bool		Snake::crash(t_coord const &coord)
{
  int		x;
  int		y;
  unsigned int	i = 2;

  x = this->_snake[0].getX();
  y = this->_snake[0].getY();
  if (x <= 0 || y <= 0 || x >= this->_width || y >= this->_height)
    return (true);
  while (i < this->_snake.size())
      {
	if (x == this->_snake[i].getX() && y == this->_snake[i].getY())
	  return (true);
	i++;
      }
  if (x == coord.x && y == coord.y)
    this->_getFood = true;
  else
    this->_getFood = false;
  return (false);
}

void	Snake::addHead()
{
  switch (this->_direction)
    {
    case LEFT:
      this->_snake.insert(this->_snake.begin(), Body(this->_snake[0]._x-1,this->_snake[0]._y));
      break;
    case RIGHT:
      this->_snake.insert(this->_snake.begin(), Body(this->_snake[0]._x+1,this->_snake[0]._y));
      break;
    case UP:
      this->_snake.insert(this->_snake.begin(), Body(this->_snake[0]._x,this->_snake[0]._y-1));
      break;
    case DOWN:
      this->_snake.insert(this->_snake.begin(), Body(this->_snake[0]._x,this->_snake[0]._y+1));
      break;
    }
}

void	Snake::startSnake(IGraphic const *graph)
{
  Food	food(this->_snake, this->_width, this->_height);
  way_t	key;

  key = K_ELSE;
  for (int i = 0; i <= 4; i++)
    graph->moveBody(this->_snake[i].getX(), this->_snake[i].getY());
  graph->putFood(food.getCoord(), this->_score);
  while (this->crash(food.getCoord()) == false && key != K_ESC)
    {
      if (this->_getFood == true)
	{
	  this->_score += 10;
	  food.setNewFood(this->_snake, this->_width, this->_height);
	  graph->putFood(food.getCoord(), this->_score);
	  this->_speed -= 2500;
	}
      key = graph->getKey();
      this->getDirection(key);
      if (this->_getFood == false)
	{
	  graph->deleteBack(this->_snake[this->_snake.size()-1].getX(), this->_snake[this->_snake.size()-1].getY());
	  this->_snake.pop_back();
	}
      if (key != K_ESC)
	{
	  this->addHead();
	  graph->moveBody(this->_snake[0].getX(), this->_snake[0].getY());
	  usleep(this->_speed);
	}
    }
}
