#include "app/app.hpp"

int main() {
  try {
    App app;
    app.run();
  }
  catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
  }
  return 0;
}