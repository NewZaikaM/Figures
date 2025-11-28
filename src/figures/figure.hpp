#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "../include_lib.hpp"

class StringConvertible {
public:
  virtual std::string toString() const = 0;
  virtual ~StringConvertible() = default;
};

class Figure : public StringConvertible {
public:
  virtual double perimeter() const = 0;
  virtual Figure* clone() const = 0;
  virtual ~Figure() = default;
};



#endif
