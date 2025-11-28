#ifndef APP_HPP
#define APP_HPP

#include "../include_lib.hpp"
#include "../factories/source_figure_factories/source_figure_factory.hpp"

class App {
  SourceFigureFactory* factory = nullptr;
  std::vector<Figure*> figures;
public:
  App() = default;
  ~App();

  void run();
private:
  void readInputSource();
  void readFigures();
  void printFigures(std::ostream& out) const;
  void cloneFigures() const;
  void saveToFile(const std::string& filename) const;
};

#endif