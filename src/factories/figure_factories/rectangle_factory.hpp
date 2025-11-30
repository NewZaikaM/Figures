#ifndef RECTANGLE_FACTORY_HPP
#define RECTANGLE_FACTORY_HPP

#include "figure_factory.hpp"


class RectangleFactory : public FigureFactory {
public:
  std::unique_ptr<Figure> createRand() const override;
  std::unique_ptr<Figure> createFrom(std::stringstream& ss) const override;
};

#endif