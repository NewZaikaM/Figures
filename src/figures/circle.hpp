#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "figure.hpp"

class Circle : public Figure, public StringConvertible {
  const double m_r;
  const double m_perimeter;
  static double computePerimeter(double r);
  public:
    Circle(double r);
    ~Circle() override  = default;
    
    double radius() const;
    double perimeter() const override;

    std::string toString() const override;
    Circle* clone() const override;
};

#endif