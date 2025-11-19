#ifndef I_FIGURE_HPP
#define I_FIGURE_HPP

#include <stdexcept>
#include <cmath>
#include <sstream>

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
