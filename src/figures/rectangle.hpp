#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "figure.hpp"

class Rectangle : public Figure {
  const double m_a;
  const double m_b;
  const double m_perimeter;
  static double computePerimeter(double a, double b);
  public:
    Rectangle(double a, double b);
    ~Rectangle() override  = default;
    
    double sideA() const;
    double sideB() const;
    double perimeter() const override;

    std::string toString() const override;
    Rectangle* clone() const override;
};

#endif