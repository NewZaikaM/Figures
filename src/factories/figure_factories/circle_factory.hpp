#ifndef CIRCLE_FACTORY_HPP
#define CIRCLE_FACTORY_HPP

#include "figure_factory.hpp"


class CircleFactory : public FigureFactory {
public:
  Figure* createRand() const override;
  Figure* createFrom(std::stringstream& ss) const override;
};

#endif