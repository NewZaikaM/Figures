#include "triangle.hpp"

double Triangle::computePerimeter(double a, double b, double c) {
        if (a <= 0 || b <= 0 || c <= 0)
            throw std::invalid_argument("Sides must be positive");

        if (a + b <= c || a + c <= b || b + c <= a)
            throw std::invalid_argument("Triangle inequality violated");

        double perim = a + b + c;

        if (!std::isfinite(perim))
            throw std::overflow_error("Perimeter overflow");

        return perim;
}

Triangle::Triangle(double a, double b, double c)
  : m_a(a), m_b(b), m_c(c), m_perimeter(computePerimeter(a, b, c)) {}

double Triangle::sideA() const {
  return m_a;
}
double Triangle::sideB() const {
  return m_b;
}
double Triangle::sideC() const {
  return m_c;  
}
double Triangle::perimeter() const {
  return m_perimeter;
}

std::string Triangle::toString() const {
  std::ostringstream out;
  out << "Triangle " << m_a << " " << m_b << " " << m_c;

  return out.str();
}
Triangle*  Triangle::clone() const {
  return new Triangle(*this);
}

