#ifndef CIRCLE_FACTORY_HPP
#define CIRCLE_FACTORY_HPP

#include "figure_factory.hpp"


class CircleFactory : public FigureFactory {
public:
 std::unique_ptr<Figure> createRand() const override;
 std::unique_ptr<Figure> createFrom(std::stringstream& ss) const override;
};

#endif