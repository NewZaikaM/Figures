#ifndef I_FIGURE_HPP
#define I_FIGURE_HPP

class IFigure {
public:
  virtual double perimeter() const = 0;
  virtual ~IFigure() = default;
};

#endif
