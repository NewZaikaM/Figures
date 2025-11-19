#include "factory.hpp"
#include "../figures/triangle.hpp"
#include "../figures/rectangle.hpp"
#include "../figures/circle.hpp"

#include <sstream>
#include <stdexcept>

Figure* FactoryFigure::create_from(const std::string& representation) const {
  std::stringstream ss(representation);
  std::string name;
  ss >> name;

  if (name.empty()) {
    throw std::invalid_argument("Empty input string");
  }

  if (name == "Triangle") {
    double a, b, c;

    if (!(ss >> a)) {
      if (ss.eof())
          throw std::invalid_argument("Too few parameters: missing side a");
      else
          throw std::invalid_argument("Non-numeric triangle parameter: side a");
    }

    if (!(ss >> b)) {
      if (ss.eof())
          throw std::invalid_argument("Too few parameters: missing side b");
      else
          throw std::invalid_argument("Non-numeric triangle parameter: side b");
    }

    if (!(ss >> c)) {
      if (ss.eof())
          throw std::invalid_argument("Too few parameters: missing side c");
      else
          throw std::invalid_argument("Non-numeric triangle parameter: side c");
    }

    return new Triangle(a, b, c);
  }
  else if (name == "Rectangle") {
    double a, b;

    if (!(ss >> a)) {
      if (ss.eof())
          throw std::invalid_argument("Too few parameters: missing side a");
      else
          throw std::invalid_argument("Non-numeric triangle parameter: side a");
    }

    if (!(ss >> b)) {
      if (ss.eof())
          throw std::invalid_argument("Too few parameters: missing side b");
      else
          throw std::invalid_argument("Non-numeric triangle parameter: side b");
    }
    
    return new Rectangle(a, b);
  } else if (name == "Circle") {
    double r;

    if (!(ss >> r)) {
      if (ss.eof())
          throw std::invalid_argument("Too few parameters: missing side b");
      else
          throw std::invalid_argument("Non-numeric triangle parameter: side b");
    }
    
    return new Circle(r);
  }
  
  throw std::invalid_argument("Unknown figure type: " + name);
}