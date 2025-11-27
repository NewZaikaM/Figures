#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "../include_lib.hpp"

class Figure {
public:
  virtual double perimeter() const = 0;
  virtual Figure* clone() const = 0;
  virtual ~Figure() = default;
};

class StringConvertible {
public:
  virtual std::string toString() const = 0;
  virtual ~StringConvertible() = default;
};

#endif
