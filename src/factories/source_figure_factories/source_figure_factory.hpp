#ifndef SOURCE_FIGURE_FACTORY_HPP
#define SOURCE_FIGURE_FACTORY_HPP

#include "../../figures/figure.hpp"
#include "../init_utils/init_utils.hpp"

class SourceFigureFactory {
public:
  virtual std::unique_ptr<Figure> create() const = 0;
  virtual ~SourceFigureFactory() = default;
};

#endif