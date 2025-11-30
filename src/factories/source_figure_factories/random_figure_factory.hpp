#ifndef RANDOM_FIGURE_FACTORY_HPP
#define RANDOM_FIGURE_FACTORY_HPP

#include "source_figure_factory.hpp"

class RandomFigureFactory: public SourceFigureFactory {
public:
    std::unique_ptr<Figure> create() const override;
};

#endif