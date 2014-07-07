//
// LoadGraph.cpp for Loadgraph in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:25:02 2014 ilyas zelloufi
// Last update Mon Jul  7 12:25:03 2014 ilyas zelloufi
//

#include "LoadGraph.hpp"
#include "Exception.hpp"

LoadGraph::LoadGraph(char const *libName)
{
  std::string	path;

  path = "./";
  path += libName;
  this->_dlobj = dlopen(path.c_str(), RTLD_LAZY);
}

LoadGraph::~LoadGraph()
{
  if (this->_dlobj != NULL)
    dlclose(this->_dlobj);
}

IGraphic	*LoadGraph::getGraph(int const &width, int const &height) const
{
  IGraphic	*(*graph)(int, int);
  void		*handle;

  if (this->_dlobj != NULL)
    {
      handle = dlsym(this->_dlobj, "getGraph");
      if (handle != NULL)
	{
	  graph = reinterpret_cast<IGraphic *(*)(int, int)>(handle);
	  return (graph(width, height));
	}
      else
	throw(Exception(dlerror()));
    }
  else
    throw(Exception(dlerror()));
  return (NULL);
}
