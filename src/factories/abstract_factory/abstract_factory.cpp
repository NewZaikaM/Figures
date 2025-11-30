#include "abstract_factory.hpp"
#include "../source_figure_factories/random_figure_factory.hpp"
#include "../source_figure_factories/stream_figure_factory.hpp"

std::unique_ptr<SourceFigureFactory> AbstractFactory::getFactory(const std::string& inputSource) {
    if (inputSource == "Random") {
        return std::make_unique<RandomFigureFactory>();
    } else {
        throw std::invalid_argument("Unknown input source without stream: " + inputSource);
    }
}


std::unique_ptr<SourceFigureFactory> AbstractFactory::getFactory(
    const std::string& inputSource, std::istream& in
) {
    if (inputSource == "Stream") {
        return std::make_unique<StreamFigureFactory>(in);
    } else {
        throw std::invalid_argument("Unknown input source with stream: " + inputSource);
    }
}