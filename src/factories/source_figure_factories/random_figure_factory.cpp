#include "random_figure_factory.hpp"

std::unique_ptr<Figure> RandomFigureFactory::create() const {
    if (RegistryFigure::figuresNames.empty()) {
        return nullptr;
    }

    int figureIndex = rand() % RegistryFigure::figuresNames.size();
    const std::string& figureName = RegistryFigure::figuresNames[figureIndex];

    FigureFactory* factory = RegistryFigure::findFactory(figureName);

    return factory->createRand();
}