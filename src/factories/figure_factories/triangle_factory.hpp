#ifndef TRIANGLE_FACTORY_HPP
#define TRIANGLE_FACTORY_HPP


#include "figure_factory.hpp"

class TriangleFactory : public FigureFactory {
public:
  std::unique_ptr<Figure> createRand() const override;
  std::unique_ptr<Figure> createFrom(std::stringstream& ss) const override;
};

#endif