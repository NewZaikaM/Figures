#ifndef TRIANGLE_FACTORY_HPP
#define TRIANGLE_FACTORY_HPP


#include "figure_factory.hpp"

class TriangleFactory : public FigureFactory {
public:
  Figure* createRand() const override;
  Figure* createFrom(std::stringstream& ss) const override;
};

#endif