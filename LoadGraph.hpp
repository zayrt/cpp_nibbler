//
// LoadGraph.hpp for nibbler in /home/tang_j/rendu/cpp_nibbler
// 
// Made by Jean Luc TANG
// Login   <tang_j@epitech.net>
// 
// Started on  Tue Apr  1 23:53:18 2014 Jean Luc TANG
// Last update Thu Apr  3 14:49:00 2014 Jean Luc TANG
//

#ifndef  LOADGRAPH_HPP_
# define LOADGRAPH_HPP_

# include <iostream>
# include <dlfcn.h>
# include "IGraphic.hpp"

class	LoadGraph
{
private:
  void	*_dlobj;

public:
  LoadGraph(char const *);
  ~LoadGraph();
  IGraphic	*getGraph(int const &, int const &) const;
};

#endif
