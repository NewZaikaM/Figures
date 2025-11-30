#ifndef INIT_UTILS_HPP
#define INIT_UTILS_HPP

#include "../../include_lib.hpp"
#include "../figure_factories/figure_factory.hpp"

namespace RegistryFigure {
  extern std::vector<std::string> figuresNames;
  extern std::unordered_map<std::string,  FigureFactory*> figuresFactories;

  void initFactories();
  FigureFactory* findFactory(const std::string& name);
}

double randomFromTo(double min, double max);

#endif

