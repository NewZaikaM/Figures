#ifndef STREAM_FIGURE_FACTORY_HPP
#define STREAM_FIGURE_FACTORY_HPP

#include "source_figure_factory.hpp"

class StreamFigureFactory: public SourceFigureFactory {
private:
  std::istream& m_stream;
  Figure* createFrom(const std::string& representation) const;
public:
  StreamFigureFactory(std::istream& in);
  Figure* create() const override;
};

#endif
