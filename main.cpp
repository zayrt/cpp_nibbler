//
// main.cpp for main in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:25:35 2014 ilyas zelloufi
// Last update Mon Jul  7 12:26:21 2014 ilyas zelloufi
//

#include <dlfcn.h>
#include <sstream>
#include "LoadGraph.hpp"
#include "IGraphic.hpp"
#include "Snake.hpp"
#include "Exception.hpp"

static void	start(char *width, char *height, char *libName)
{
  int		my_width;
  int		my_height;

  try{
    std::istringstream iss(width);
    iss >> my_width;
    iss.clear();
    iss.str(height);
    iss >> my_height;
    if (my_height < 10 || my_width < 10)
      throw(Exception("Width and height must be equal or greater than 10 and smaller than 10"));
    LoadGraph	load(libName);
    IGraphic	*graph;
    srand(time(NULL));
    graph = load.getGraph(my_width, my_height);
    if (graph != NULL)
      {
	Snake	snake(my_width, my_height);
	snake.startSnake(graph);
	delete graph;
	std::cout << "Game over" << std::endl;
	std::cout << "Your score is " << snake.getScore() << std::endl;
      }
  }catch (Exception const &error){
    std::cerr << "Error: " << error.what() << std::endl;}
}

int		main(int ac, char **av)
{
  if (ac == 4)
    start(av[1], av[2], av[3]);
  else
    std::cout << "Usage: ./nibbler width height lib_nibbler_[libname].so" << std::endl;
  return (0);
}
