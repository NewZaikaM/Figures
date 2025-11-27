#include "init_utils.hpp"
#include "../figure_factories/triangle_factory.hpp"
#include "../figure_factories/rectangle_factory.hpp"
#include "../figure_factories/circle_factory.hpp"

namespace RegistryFigure {
  std::vector<std::string> figuresNames = {"Triangle", "Rectangle", "Circle"};

  std::unordered_map<std::string, std::unique_ptr<FigureFactory>> figuresFactories;

  void initFactories() {
    figuresFactories.emplace("Triangle", std::make_unique<TriangleFactory>());
    figuresFactories.emplace("Rectangle", std::make_unique<RectangleFactory>());
    figuresFactories.emplace("Circle", std::make_unique<CircleFactory>());
  }

  FigureFactory* findFactory(const std::string& name) {
    auto it = figuresFactories.find(name);
    if (it == figuresFactories.end())
      throw std::invalid_argument("Unknown figure type: " + name);

    return it->second.get();
  }
}

double randomFromTo(double min, double max) {
  return min + (double(rand()) / RAND_MAX) * (max - min);
}