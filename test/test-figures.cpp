#define _USE_MATH_DEFINES

#include "catch2/catch_all.hpp"
#include "../src/figures/triangle.hpp"
#include "../src/figures/rectangle.hpp"
#include "../src/figures/circle.hpp"
#include "../src/factories/factory.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>

//Triangle
TEST_CASE( "Triangle with negative sides", "[triangle][negative_sides]" ) {
  REQUIRE_THROWS_AS( Triangle(-1, 1, 1), std::invalid_argument);
  REQUIRE_THROWS_AS( Triangle(1, -1, 1), std::invalid_argument);
  REQUIRE_THROWS_AS( Triangle(1, 1, -1), std::invalid_argument);
}
TEST_CASE( "Triangle with non-valid sides", "[triangle][non-valid_sides]" ) {
  REQUIRE_THROWS_AS( Triangle(3, 2, 5), std::invalid_argument);
  REQUIRE_THROWS_AS( Triangle(5, 2, 3), std::invalid_argument);
  REQUIRE_THROWS_AS( Triangle(3, 5, 2), std::invalid_argument);
}
TEST_CASE( "Triangle with overflow perimeter", "[triangle][overflow]" ) {
  double x = std::numeric_limits<double>::max();
  REQUIRE_THROWS_AS( Triangle(x, x, x), std::overflow_error);
}
TEST_CASE( "Triangle correct perimeter", "[triangle][perimeter]" ) {
  REQUIRE( Triangle(3, 4, 5).perimeter() == (3 + 4 + 5));
}
TEST_CASE( "Triangle to_string format", "[triangle][to_string]" ) {
  REQUIRE( Triangle(3, 4, 5).toString() == "Triangle 3 4 5");
}

//Rectangle
TEST_CASE( "Rectangle with negative sides", "[rectangle][negative_sides]" ) {
  REQUIRE_THROWS_AS( Rectangle(-1, 1), std::invalid_argument);
  REQUIRE_THROWS_AS( Rectangle(1, -1), std::invalid_argument);
}
TEST_CASE( "Rectangle with overflow perimeter", "[rectangle][overflow]" ) {
  double x = std::numeric_limits<double>::max();
  REQUIRE_THROWS_AS( Rectangle(x, x), std::overflow_error);
}
TEST_CASE( "Rectangle correct perimeter", "[rectangle][perimeter]" ) {
  REQUIRE( Rectangle(3, 4).perimeter() == (3*2 + 4*2));
}
TEST_CASE( "Rectangle to_string format", "[rectangle][to_string]" ) {
  REQUIRE( Rectangle(3, 4).toString() == "Rectangle 3 4");
}

//Circle
TEST_CASE( "Circle with negative sides", "[circle][negative_sides]" ) {
  REQUIRE_THROWS_AS( Circle(-1), std::invalid_argument);
}
TEST_CASE( "Circle with overflow perimeter", "[circle][overflow]" ) {
  double x = std::numeric_limits<double>::max();
  REQUIRE_THROWS_AS( Circle(x), std::overflow_error);
}
TEST_CASE( "Circle correct perimeter", "[circle][perimeter]" ) {
  REQUIRE( Circle(3).perimeter() == (2.0 * M_PI * 3));
}
TEST_CASE( "Circle to_string format", "[circle][to_string]" ) {
  REQUIRE( Circle(3).toString() == "Circle 3");
}

//Prototype
TEST_CASE("Clone id type", "[prototype][clone_id_type]") {
  Figure* org_triangle = new Triangle(3, 4, 5);
  Figure* copy_triangle = org_triangle->clone();

  REQUIRE( typeid(*org_triangle) == typeid(*copy_triangle));
  delete org_triangle; 
  delete copy_triangle;
  
  Figure* org_rectangle = new Rectangle(3, 4);
  Figure* copy_rectangle = org_rectangle->clone();

  REQUIRE( typeid(*org_rectangle) == typeid(*copy_rectangle));
  delete org_rectangle; 
  delete copy_rectangle;
  
  Figure* org_circle = new Circle(3);
  Figure* copy_circle = org_circle->clone();

  REQUIRE( typeid(*org_circle) == typeid(*copy_circle));
  delete org_circle; 
  delete copy_circle;
}  
TEST_CASE("Clone diff reference", "[prototype][clone_diff_ref]") {
  Figure* org_triangle = new Triangle(3, 4, 5);
  Figure* copy_triangle = org_triangle->clone();

  REQUIRE( org_triangle != copy_triangle);
  delete org_triangle; 
  delete copy_triangle;
  
  Figure* org_rectangle = new Rectangle(3, 4);
  Figure* copy_rectangle = org_rectangle->clone();

  REQUIRE( org_rectangle != copy_rectangle);
  delete org_rectangle; 
  delete copy_rectangle;
  
  Figure* org_circle = new Circle(3);
  Figure* copy_circle = org_circle->clone();

  REQUIRE( org_circle != copy_circle);
  delete org_circle; 
  delete copy_circle;
}  
TEST_CASE("Clone data", "[prototype][clone_data]") {
  Triangle* org_triangle = new Triangle(3, 4, 5);
  Triangle* copy_triangle = org_triangle->clone();

  REQUIRE( org_triangle->sideA() == copy_triangle->sideA());
  REQUIRE( org_triangle->sideB() == copy_triangle->sideB());
  REQUIRE( org_triangle->sideC() == copy_triangle->sideC());
  REQUIRE( org_triangle->perimeter() == copy_triangle->perimeter());
  delete org_triangle; 
  delete copy_triangle;

  Rectangle* org_rectangle = new Rectangle(3, 4);
  Rectangle* copy_rectangle = org_rectangle->clone();

  REQUIRE( org_rectangle->sideA() == copy_rectangle->sideA());
  REQUIRE( org_rectangle->sideB() == copy_rectangle->sideB());
  REQUIRE( org_rectangle->perimeter() == copy_rectangle->perimeter());
  delete org_rectangle; 
  delete copy_rectangle;

  Circle* org_circle = new Circle(3);
  Circle* copy_circle = org_circle->clone();

  REQUIRE( org_circle->radius() == copy_circle->radius());
  REQUIRE( org_circle->perimeter() == copy_circle->perimeter());
  delete org_circle; 
  delete copy_circle;
}  

//Factory
TEST_CASE( "Figure factory from empty string", "[factory][empty_string]" ) {
  REQUIRE_THROWS_AS( FactoryFigure().create_from(""), std::invalid_argument);
  REQUIRE_THROWS_AS( FactoryFigure().create_from("    "), std::invalid_argument);
  REQUIRE_THROWS_AS( FactoryFigure().create_from("\n \n"), std::invalid_argument);
}
TEST_CASE( "Figure factory from too few parameters", "[factory][few_param]" ) {
  REQUIRE_THROWS_AS( FactoryFigure().create_from("Triangle 3 4 "), std::invalid_argument);
  REQUIRE_THROWS_AS( FactoryFigure().create_from("Rectangle 3 "), std::invalid_argument);
  REQUIRE_THROWS_AS( FactoryFigure().create_from("Circle "), std::invalid_argument);
}
TEST_CASE( "Figure factory from non-numeric parameters", "[factory][non-num_param]" ) {
  REQUIRE_THROWS_AS( FactoryFigure().create_from("Triangle 3 4 abc"), std::invalid_argument);
  REQUIRE_THROWS_AS( FactoryFigure().create_from("Rectangle 3 abc"), std::invalid_argument);
  REQUIRE_THROWS_AS( FactoryFigure().create_from("Circle abc"), std::invalid_argument);
}
TEST_CASE( "Figure factory from unknown name", "[factory][unknown_name]" ) {
  REQUIRE_THROWS_AS( FactoryFigure().create_from("Test1 3 4 abc"), std::invalid_argument);
}