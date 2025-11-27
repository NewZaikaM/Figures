#include "stream_figure_factory.hpp"

Figure* StreamFigureFactory::createFrom(const std::string& representation) const {
  std::stringstream ss(representation);
  std::string name;
  ss >> name;

  if (name.empty()) {
    throw std::invalid_argument("Empty input string");
  }
  
  const FigureFactory* factory = RegistryFigure::findFactory(name);
  
  return factory->createFrom(ss);
}

StreamFigureFactory::StreamFigureFactory(std::istream& in) : m_stream(in) {}

Figure* StreamFigureFactory::create() const {
  std::string line;
  while (std::getline(m_stream, line)) {
    try {
      return createFrom(line);
    } catch (...) {}
  }

  return nullptr;
}