//
// Exception.hpp for exception in /home/zellou_i/rendu/cpp_nibbler
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:23:45 2014 ilyas zelloufi
// Last update Mon Jul  7 12:23:47 2014 ilyas zelloufi
//

#ifndef	 EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <iostream>
# include <fstream>
# include <string>
# include <exception>
# include "IGraphic.hpp"

class	Exception : public std::exception
{
 private:
  std::string	_msg;
 public:
  Exception(std::string const &msg) throw();
  virtual ~Exception() throw();
  virtual const char *what() const throw();
};

#endif /* !EXCEPTION */
