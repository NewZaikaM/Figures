#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <stdexcept>
#include <cmath>

double Circle::computePerimeter(double r) {
  if (r <= 0)
    throw std::invalid_argument("Radius must be positive");
  
  double perim = 2.0 * M_PI * r;
  if (!std::isfinite(perim))
    throw std::overflow_error("Perimeter overflow");

  return perim;
}

Circle::Circle(double r) 
  : m_r(r), m_perimeter(computePerimeter(r)) {}

double Circle::radius() const {
  return m_r;
}
double Circle::perimeter() const {
  return m_perimeter;
}