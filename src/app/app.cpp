#include "app.hpp"
#include "../factories/abstract_factory/abstract_factory.hpp"

App::~App() {
  delete factory;

  for (Figure* f : figures) {
      delete f;
  }
}

void App::run() {
  std::srand(std::time(nullptr));
  RegistryFigure::initFactories();
  readInputSource();
  readFigures();

  std::cout << "\n--- FIGURES ---\n";
  printFigures(std::cout);

  std::cout << "\n--- CLONED FIGURES ---\n";
  cloneFigures();

  saveToFile("figures.txt");
  std::cout << "\nSaved to figures.txt\n";
}

void App::readInputSource() {
  std::string source;
  std::cout << "Choose input source (Random / Stream / File): ";
  std::cin >> source;

  if (source == "Stream") {
    factory = AbstractFactory::getFactory(source, &std::cin);
  } else if (source == "File") {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ifstream* fin = new std::ifstream(filename);
    if (!fin->is_open()) {
      delete fin;
      throw std::runtime_error("Cannot open file: " + filename);
    }

    factory = AbstractFactory::getFactory("Stream", fin);
  } else if (source == "Random") {
    factory = AbstractFactory::getFactory(source);
  }

  if (!factory) {
    throw std::runtime_error("Unknown input source: " + source);
  }
}

void App::readFigures() {
    int N;
    std::cout << "Enter number of figures: ";
    std::cin >> N;

    figures.reserve(N);

    for (int i = 0; i < N; ++i) {
      Figure* fig = factory->create();
      if (!fig) {
        std::cerr << "Failed to read figure #" << (i + 1) << "\n";
        continue;
      }
      figures.push_back(fig);
    }
}

void App::printFigures(std::ostream& out) const {
  for (Figure* f : figures) {
    out << f->toString() << "\n";
  }
}

void App::cloneFigures() const {
  for (Figure* f : figures) {
    Figure* clone = f->clone();
    if (clone) {
    std::cout << clone->toString() << "\n";
    delete clone;
    }
  }
}

void App::saveToFile(const std::string& filename) const {
  std::ofstream out(filename);
  if (!out.is_open()) {
    std::cerr << "Can't open file for writing.\n";
    return;
  }
  printFigures(out);
}

















