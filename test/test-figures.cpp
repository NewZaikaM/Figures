#define _USE_MATH_DEFINES

#include "catch2/catch_all.hpp"
#include "../src/include_lib.hpp"
#include "../src/factories/init_utils/init_utils.hpp"
#include "../src/figures/figure.hpp"
#include "../src/figures/triangle.hpp"
#include "../src/figures/rectangle.hpp"
#include "../src/figures/circle.hpp"
#include "../src/factories/source_figure_factories/random_figure_factory.hpp"
#include "../src/factories/source_figure_factories/stream_figure_factory.hpp"
#include "../src/factories/abstract_factory/abstract_factory.hpp"

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

//FigureFactory
TEST_CASE( "TriangleFactory random", "[triangle][figure_factory][random]" ) {
  RegistryFigure::initFactories();
  const int N = 10000;
  for (int i = 0; i < N; i++) {
    Triangle* t = dynamic_cast<Triangle*>(
      RegistryFigure::findFactory("Triangle")->createRand()
    );
    REQUIRE(t != nullptr);

    REQUIRE(t->sideA() >= 1);
    REQUIRE(t->sideA() <= 100);
    REQUIRE(t->sideB() >= 1);
    REQUIRE(t->sideB() <= 100);

    double min_c = fabs(t->sideA() - t->sideB()) + 0.0001;
    double max_c = t->sideA() + t->sideB() - 0.0001;

    REQUIRE(t->sideC() >= min_c);
    REQUIRE(t->sideC() <= max_c);

    delete t;
  }
}
TEST_CASE( "RectangleFactory random", "[rectangle][figure_factory][random]" ) {
  RegistryFigure::initFactories();
  const int N = 10000;
  for (int i = 0; i < N; i++) {
    Rectangle* r = dynamic_cast<Rectangle*>(
      RegistryFigure::findFactory("Rectangle")->createRand()
    );
    REQUIRE(r != nullptr);

    REQUIRE(r->sideA() >= 1);
    REQUIRE(r->sideA() <= 100);
    REQUIRE(r->sideB() >= 1);
    REQUIRE(r->sideB() <= 100);

    delete r;
  }
}
TEST_CASE( "CircleFactory random", "[circle][figure_factory][random]" ) {
  RegistryFigure::initFactories();
  const int N = 10000;
  for (int i = 0; i < N; i++) {
    Circle* c = dynamic_cast<Circle*>(
      RegistryFigure::findFactory("Circle")->createRand()
    );
    REQUIRE(c != nullptr);

    REQUIRE(c->radius() >= 1);
    REQUIRE(c->radius() <= 100);

    delete c;
  }
}
TEST_CASE( "TriangleFactory sstream", "[triangle][figure_factory][sstream]" ) {
  RegistryFigure::initFactories();

  std::string triangleStr = "3 4 5";
  std::stringstream ss(triangleStr);

  Triangle* t = dynamic_cast<Triangle*>(
    RegistryFigure::findFactory("Triangle")->createFrom(ss)
  );

  REQUIRE(t != nullptr);

  REQUIRE(t->sideA() == 3);
  REQUIRE(t->sideB() == 4);
  REQUIRE(t->sideC() == 5);

  REQUIRE(t->perimeter() == 12);

  delete t;
}
TEST_CASE("TriangleFactory sstream errors", "[triangle][figure_factory][sstream]") {
  RegistryFigure::initFactories();
  {
    std::stringstream ss("3 4");
    REQUIRE_THROWS_AS(
      RegistryFigure::findFactory("Triangle")->createFrom(ss),
      std::invalid_argument
    );
  }
  {
    std::stringstream ss("3 a 5");
    REQUIRE_THROWS_AS(
      RegistryFigure::findFactory("Triangle")->createFrom(ss),
      std::invalid_argument
    );
  }
  {
    std::stringstream ss("3 4 5 6");
    REQUIRE_THROWS_AS(
      RegistryFigure::findFactory("Triangle")->createFrom(ss),
      std::invalid_argument
    );
  }
}
TEST_CASE("RectangleFactory sstream", "[rectangle][figure_factory][sstream]") {
  RegistryFigure::initFactories();

  std::string rectStr = "5 10";
  std::stringstream ss(rectStr);

  Rectangle* r = dynamic_cast<Rectangle*>(
    RegistryFigure::findFactory("Rectangle")->createFrom(ss)
  );

  REQUIRE(r != nullptr);

  REQUIRE(r->sideA() == 5);
  REQUIRE(r->sideB() == 10);
  REQUIRE(r->perimeter() == 30);

  delete r;
}
TEST_CASE("RectangleFactory sstream errors", "[rectangle][figure_factory][sstream]") {
  RegistryFigure::initFactories();
  {
    std::stringstream ss("5");
    REQUIRE_THROWS_AS(
      RegistryFigure::findFactory("Rectangle")->createFrom(ss),
      std::invalid_argument
    );
  }
  {
    std::stringstream ss("5 x");
    REQUIRE_THROWS_AS(
      RegistryFigure::findFactory("Rectangle")->createFrom(ss),
      std::invalid_argument
    );
  }
  {
    std::stringstream ss("5 10 15");
    REQUIRE_THROWS_AS(
      RegistryFigure::findFactory("Rectangle")->createFrom(ss),
      std::invalid_argument
    );
  }
}
TEST_CASE("CircleFactory sstream", "[circle][figure_factory][sstream]") {
  RegistryFigure::initFactories();

  std::string circleStr = "7";
  std::stringstream ss(circleStr);

  Circle* c = dynamic_cast<Circle*>(
      RegistryFigure::findFactory("Circle")->createFrom(ss)
  );

  REQUIRE(c != nullptr);

  REQUIRE(c->radius() == 7);
  double expected = 2 * M_PI * 7;
  REQUIRE(std::abs(c->perimeter() - expected) < 1e-6);

  delete c;
}
TEST_CASE("CircleFactory sstream errors", "[circle][figure_factory][sstream]") {
  RegistryFigure::initFactories();
  {
    std::stringstream ss("");
    REQUIRE_THROWS_AS(
      RegistryFigure::findFactory("Circle")->createFrom(ss),
      std::invalid_argument
    );
  }
  {
    std::stringstream ss("r");
    REQUIRE_THROWS_AS(
      RegistryFigure::findFactory("Circle")->createFrom(ss),
      std::invalid_argument
    );
  }
  {
    std::stringstream ss("5 6");
    REQUIRE_THROWS_AS(
      RegistryFigure::findFactory("Circle")->createFrom(ss),
      std::invalid_argument
    );
  }
}

//RegistryFigure
TEST_CASE("RegistryFigure initFactories", "[registry][init]") {
  RegistryFigure::initFactories();

  REQUIRE(RegistryFigure::figuresFactories.size() == 3);
  REQUIRE(RegistryFigure::figuresFactories.find("Triangle") != RegistryFigure::figuresFactories.end());
  REQUIRE(RegistryFigure::figuresFactories.find("Rectangle") != RegistryFigure::figuresFactories.end());
  REQUIRE(RegistryFigure::figuresFactories.find("Circle") != RegistryFigure::figuresFactories.end());
}
TEST_CASE("RegistryFigure findFactory", "[registry][findFactory]") {
  RegistryFigure::initFactories();

  REQUIRE_NOTHROW(RegistryFigure::findFactory("Triangle"));
  REQUIRE_NOTHROW(RegistryFigure::findFactory("Rectangle"));
  REQUIRE_NOTHROW(RegistryFigure::findFactory("Circle"));

  REQUIRE_THROWS_AS(RegistryFigure::findFactory("Hexagon"), std::invalid_argument);
}

//function randomFromTo
TEST_CASE("randomFromTo produces values in range", "[random]") {
  const double min = 5.0;
  const double max = 10.0;
  const int N = 1000;

  for (int i = 0; i < N; ++i) {
    double val = randomFromTo(min, max);
    REQUIRE(val >= min);
    REQUIRE(val <= max);
  }
}
TEST_CASE("randomFromTo can produce min and max approximately", "[random]") {
  const double min = 0.0;
  const double max = 1.0;
  bool hitMin = false;
  bool hitMax = false;
  const int N = 100000;

  for (int i = 0; i < N; ++i) {
    double val = randomFromTo(min, max);
    if (val <= min + 1e-6) hitMin = true;
    if (val >= max - 1e-6) hitMax = true;
    if (hitMin && hitMax) break;
  }

  REQUIRE(hitMin);
  REQUIRE(hitMax);
}

//SourceFigureFactory
TEST_CASE("RandomFigureFactory basic functionality", "[random_factory][source_factory]") {
  RegistryFigure::initFactories();

  RandomFigureFactory rf;

  bool gotTriangle = false;
  bool gotRectangle = false;
  bool gotCircle = false;

  for (int i = 0; i < 200; ++i) {
    Figure* f = rf.create();
    REQUIRE(f != nullptr);

    if (dynamic_cast<Triangle*>(f)) gotTriangle = true;
    else if (dynamic_cast<Rectangle*>(f)) gotRectangle = true;
    else if (dynamic_cast<Circle*>(f)) gotCircle = true;
    else FAIL("Unknown figure type returned by RandomFigureFactory");

    delete f;
  }

  REQUIRE(gotTriangle);
  REQUIRE(gotRectangle);
  REQUIRE(gotCircle);
}
TEST_CASE("RandomFigureFactory returns nullptr when no figures", "[random_factory][source_factory]") {
  auto backup = RegistryFigure::figuresNames;

  RegistryFigure::figuresNames.clear();

  RandomFigureFactory rf;
  Figure* result = rf.create();

  REQUIRE(result == nullptr);

  RegistryFigure::figuresNames = backup;
}
TEST_CASE("StreamFigureFactory create - triangle", "[stream_factory][source_factory]") {
  RegistryFigure::initFactories();

  std::stringstream input("Triangle 3 4 5\n");
  StreamFigureFactory sff(input);

  Figure* f = sff.create();
  REQUIRE(f != nullptr);

  Triangle* t = dynamic_cast<Triangle*>(f);
  REQUIRE(t != nullptr);
  REQUIRE(t->sideA() == 3);
  REQUIRE(t->sideB() == 4);
  REQUIRE(t->sideC() == 5);

  delete f;
}
TEST_CASE("StreamFigureFactory create - skip invalid lines", "[stream_factory][source_factory]") {
  RegistryFigure::initFactories();

  std::stringstream input(
    "bad line\n"
    "Triangle 3 x 4\n"
    "Rectangle 5 6\n"
  );

  StreamFigureFactory sff(input);

  Figure* f = sff.create();
  REQUIRE(f != nullptr);

  Rectangle* r = dynamic_cast<Rectangle*>(f);
  REQUIRE(r != nullptr);
  REQUIRE(r->sideA() == 5);
  REQUIRE(r->sideB() == 6);

  delete f;
}
TEST_CASE("StreamFigureFactory create - no valid lines", "[stream_factory][source_factory]") {
  RegistryFigure::initFactories();

  std::stringstream input(
    "bad\n"
    "Triangle x y z\n"
    "Circle 1 2\n"
  );

  StreamFigureFactory sff(input);

  Figure* f = sff.create();
  REQUIRE(f == nullptr);
}

//AbstractFactory
TEST_CASE("AbstractFactory creates correct factories", "[abstract_factory]") {
    SourceFigureFactory* randomFactory = AbstractFactory::getFactory("Random");
    REQUIRE(dynamic_cast<RandomFigureFactory*>(randomFactory) != nullptr);
    delete randomFactory;

    std::istringstream input("test data");
    SourceFigureFactory* streamFactory = AbstractFactory::getFactory("Stream", &input);
    REQUIRE(dynamic_cast<StreamFigureFactory*>(streamFactory) != nullptr);
    delete streamFactory;
}
TEST_CASE("AbstractFactory throws exceptions", "[abstract_factory]") {
    REQUIRE_THROWS_AS(AbstractFactory::getFactory("Stream"), std::invalid_argument);
    REQUIRE_THROWS_AS(AbstractFactory::getFactory("UnknownType"), std::invalid_argument);
}
















