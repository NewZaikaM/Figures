#ifndef RECTANGLE_FACTORY_HPP
#define RECTANGLE_FACTORY_HPP

#include "figure_factory.hpp"


class RectangleFactory : public FigureFactory {
public:
  Figure* createRand() const override;
  Figure* createFrom(std::stringstream& ss) const override;
};

#endif