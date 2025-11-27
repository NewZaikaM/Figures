#ifndef FIGURE_FACTORY_HPP
#define FIGURE_FACTORY_HPP

#include "../../figures/figure.hpp"

class FigureFactory {
public:
  virtual Figure* createRand() const = 0;
  virtual Figure* createFrom(std::stringstream& ss) const = 0;
  virtual ~FigureFactory() = default;
};

#endif