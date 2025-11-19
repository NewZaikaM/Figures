#ifndef FACTORY_TRIANGLE_HPP
#define FACTORY_TRIANGLE_HPP

#include "factory.hpp"
#include "../figures/triangle.hpp"

class StringToTriangle : public StringToFigure {
public:
  Triangle* create_from(std::string representation) const override {
    return new Triangle(3, 4, 5);
  }
};

#endif