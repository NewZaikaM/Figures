#include "app.hpp"
#include "../factories/abstract_factory/abstract_factory.hpp"

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
    factory = AbstractFactory::getFactory(source, std::cin);
  } else if (source == "File") {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    fileStream = std::make_unique<std::ifstream>(filename);

    if (!fileStream->is_open()) {
      throw std::runtime_error("Cannot open file: " + filename);
    }

    factory = AbstractFactory::getFactory("Stream", *fileStream);
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
      std::unique_ptr<Figure> figure = factory->create();
      if (!figure) {
        std::cerr << "Failed to read figure #" << (i + 1) << "\n";
        continue;
      }
      figures.push_back(std::move(figure));
    }
}

void App::printFigures(std::ostream& out) const {
  for (const auto& figure : figures) {
    out << figure->toString() << "\n";
  }
}

void App::cloneFigures() const {
  for (const std::unique_ptr<Figure>& figure : figures) {
    std::unique_ptr<Figure> clone(figure->clone());
    if (clone) {
      std::cout << clone->toString() << "\n";
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

















