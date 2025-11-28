#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include "../source_figure_factories/source_figure_factory.hpp"

class AbstractFactory {
public:
static SourceFigureFactory* getFactory(const std::string& inputSource, std::istream* in = nullptr);
};

#endif