#define _USE_MATH_DEFINES

#include "catch2/catch_all.hpp"
#include "../src/figures/triangle.hpp"
#include "../src/figures/rectangle.hpp"
#include "../src/figures/circle.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>

//Triangle
TEST_CASE( "Triangle with negative sides", "[Triangle][Negative_Sides]" ) {
  REQUIRE_THROWS_AS( Triangle(-1, 1, 1), std::invalid_argument);
  REQUIRE_THROWS_AS( Triangle(1, -1, 1), std::invalid_argument);
  REQUIRE_THROWS_AS( Triangle(1, 1, -1), std::invalid_argument);
}
TEST_CASE( "Triangle with non-valid sides", "[Triangle][Non-valid_Sides]" ) {
  REQUIRE_THROWS_AS( Triangle(3, 2, 5), std::invalid_argument);
  REQUIRE_THROWS_AS( Triangle(5, 2, 3), std::invalid_argument);
  REQUIRE_THROWS_AS( Triangle(3, 5, 2), std::invalid_argument);
}
TEST_CASE( "Triangle with overflow perimeter", "[Triangle][Overflow]" ) {
  double x = std::numeric_limits<double>::max();
  REQUIRE_THROWS_AS( Triangle(x, x, x), std::overflow_error);
}
TEST_CASE( "Triangle correct perimeter", "[Triangle][Perimeter]" ) {
  REQUIRE( Triangle(3, 4, 5).perimeter() == (3 + 4 + 5));
}

//Rectangle
TEST_CASE( "Rectangle with negative sides", "[Rectangle][Negative_Sides]" ) {
  REQUIRE_THROWS_AS( Rectangle(-1, 1), std::invalid_argument);
  REQUIRE_THROWS_AS( Rectangle(1, -1), std::invalid_argument);
}
TEST_CASE( "Rectangle with overflow perimeter", "[Rectangle][Overflow]" ) {
  double x = std::numeric_limits<double>::max();
  REQUIRE_THROWS_AS( Rectangle(x, x), std::overflow_error);
}
TEST_CASE( "Rectangle correct perimeter", "[Rectangle][Perimeter]" ) {
  REQUIRE( Rectangle(3, 4).perimeter() == (3*2 + 4*2));
}

//Circle
TEST_CASE( "Circle with negative sides", "[Circle][Negative_Sides]" ) {
  REQUIRE_THROWS_AS( Circle(-1), std::invalid_argument);
}
TEST_CASE( "Circle with overflow perimeter", "[Circle][Overflow]" ) {
  double x = std::numeric_limits<double>::max();
  REQUIRE_THROWS_AS( Circle(x), std::overflow_error);
}
TEST_CASE( "Circle correct perimeter", "[Circle][Perimeter]" ) {
  REQUIRE( Circle(3).perimeter() == (2.0 * M_PI * 3));
}
