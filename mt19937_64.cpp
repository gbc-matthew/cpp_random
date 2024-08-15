#include <iostream>
#include <random>

int main() {
  std::random_device rd;
  std::mt19937_64 generator(rd());

  // Define the range you want, e.g., from -1000.0 to 1000.0
  double min_value = -1000.0;
  double max_value = 1000.0;

  std::uniform_real_distribution<double> distribution(min_value, max_value);

  for (int i = 0; i < 10; ++i) {
    double random_double = distribution(generator);
    std::cout << random_double << std::endl;
  }

  return 0;
}
