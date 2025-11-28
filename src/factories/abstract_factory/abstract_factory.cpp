#include "abstract_factory.hpp"
#include "../source_figure_factories/random_figure_factory.hpp"
#include "../source_figure_factories/stream_figure_factory.hpp"

SourceFigureFactory* AbstractFactory::getFactory(const std::string& inputSource, std::istream* in) {
  if(inputSource == "Random") {
    return new RandomFigureFactory();
  } else if(inputSource == "Stream") {
    if (!in) {
      throw std::invalid_argument("Stream input requires a valid stream");
    }
    return new StreamFigureFactory(*in);
  } else {
    throw std::invalid_argument("Unknown input sourse: " + inputSource);
  }
}