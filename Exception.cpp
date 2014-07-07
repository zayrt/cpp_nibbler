//
// Exception.cpp for  in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:23:57 2014 ilyas zelloufi
// Last update Mon Jul  7 12:23:58 2014 ilyas zelloufi
//

#include "Exception.hpp"

Exception::Exception(std::string const &msg) throw()
{
  this->_msg = msg;
}

Exception::~Exception() throw()
{

}

const char	*Exception::what() const throw()
{
  return (this->_msg.c_str());
}
