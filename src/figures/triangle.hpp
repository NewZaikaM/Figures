#ifndef TRINAGLE_HPP
#define TRIANGLE_HPP

#include "figure.hpp"

class Triangle : public Figure, public StringConvertible {
  const double m_a;
  const double m_b;
  const double m_c;
  const double m_perimeter;
  static double computePerimeter(double a, double b, double c);
  public:
    Triangle(double a, double b, double c);
    ~Triangle() override  = default;
    
    double sideA() const;
    double sideB() const;
    double sideC() const;
    double perimeter() const override;
    
    std::string toString() const override;
    Triangle* clone() const override;
};

#endif