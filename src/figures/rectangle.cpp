#include "rectangle.hpp"

double Rectangle::computePerimeter(double a, double b) {
  if (a <= 0 || b <= 0)
    throw std::invalid_argument("Sides must be positive");
  double perim = 2.0 * a + 2.0 * b;
  if (!std::isfinite(perim))
      throw std::overflow_error("Perimeter overflow");
  return perim;
}

Rectangle::Rectangle(double a, double b) 
  : m_a(a), m_b(b), m_perimeter(computePerimeter(a, b)) {}

double Rectangle::sideA() const {
  return m_a;
}
double Rectangle::sideB() const {
  return m_b;
}
double Rectangle::perimeter() const {
  return m_perimeter;
}

std::string Rectangle::to_string() const {
  std::ostringstream out;
  out << "Rectangle: " << m_a << " " << m_b;

  return out.str();
}
Rectangle* Rectangle::clone() const {
  return new Rectangle(*this);
}
