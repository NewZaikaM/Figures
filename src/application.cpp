#include "include_lib.hpp"
#include "factories/init_utils/init_utils.hpp"

int main() {
  std::srand(std::time(nullptr));
  RegistryFigure::initFactories();
  return 0;
}