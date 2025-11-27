#include "rectangle_factory.hpp"
#include "../init_utils/init_utils.hpp"
#include "../../figures/rectangle.hpp"

Figure* RectangleFactory::createRand() const {
  return new Rectangle(randomFromTo(1, 100), randomFromTo(1, 100));
}

Figure* RectangleFactory::createFrom(std::stringstream& ss) const {
  double a, b;
  
  if (!(ss >> a)) {
    if (ss.eof())
      throw std::invalid_argument("Too few parameters: missing side a");
    else
      throw std::invalid_argument("Non-numeric rectangle parameter: side a");
  }

  if (!(ss >> b)) {
    if (ss.eof())
      throw std::invalid_argument("Too few parameters: missing side b");
    else
      throw std::invalid_argument("Non-numeric rectangle parameter: side b");
  }
  
  if (ss >> std::ws && !ss.eof())
    throw std::invalid_argument("Too many parameters for rectangle");
  
  return new Rectangle(a, b);
}
