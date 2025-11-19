#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../figures/figure.hpp"

class FactoryFigure {
public:
  Figure* create_from(const std::string& representation) const;
};

#endif