#include "circle_factory.hpp"
#include "../init_utils/init_utils.hpp"
#include "../../figures/circle.hpp"

Figure* CircleFactory::createRand() const {
  return new Circle(randomFromTo(1, 100));
}

Figure* CircleFactory::createFrom(std::stringstream& ss) const {
  double r;

  if (!(ss >> r)) {
    if (ss.eof())
      throw std::invalid_argument("Too few parameters: missing radius");
    else
      throw std::invalid_argument("Non-numeric triangle parameter: radius");
  }

  if (ss >> std::ws && !ss.eof())
    throw std::invalid_argument("Too many parameters for circle");
  
  return new Circle(r);
}