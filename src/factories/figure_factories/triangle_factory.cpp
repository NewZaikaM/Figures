#include "triangle_factory.hpp"
#include "../init_utils/init_utils.hpp"
#include "../../figures/triangle.hpp"

std::unique_ptr<Figure> TriangleFactory::createRand() const {
  double a = randomFromTo(1, 100);
  double b = randomFromTo(1, 100);
  double epsilon = 0.0001;
  double min_c = std::fabs(a - b) +  epsilon; 
  double max_c = (a + b) - epsilon;

  if (min_c >= max_c) {
    max_c = a + b - 0.001;
  }
  
  double c = randomFromTo(min_c, max_c);

  return std::make_unique<Triangle>(a, b, c);
}

std::unique_ptr<Figure> TriangleFactory::createFrom(std::stringstream& ss) const {
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

  if (ss >> std::ws && !ss.eof())
    throw std::invalid_argument("Too many parameters for triangle");

  return std::make_unique<Triangle>(a, b, c);
}