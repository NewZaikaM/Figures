#ifndef I_FIGURE_HPP
#define I_FIGURE_HPP

#include <stdexcept>
#include <cmath>
#include <sstream>

class IFigure {
public:
  virtual double perimeter() const = 0;
  virtual ~IFigure() = default;
};

class StringConvertible {
public:
  virtual std::string to_string() const = 0;
  virtual ~StringConvertible() = default;
};

#endif
