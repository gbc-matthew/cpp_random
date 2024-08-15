// Random Number generator using the ranlux48 generator in std::random
// User selects the range of numbers with min, and max.

#include <iostream>
#include <random>
#include <cstdint>

class RandomInt64Gen{
 public:
  RandomInt64Gen() : rd_(), gen_(rd_()), dist_() {} // Constructor

  int64_t operator()(int64_t min, int64_t max) { 
    dist_.param(std::uniform_int_distribution<int64_t>::param_type(min, max));
    return dist_(gen_);
  }

 private:
  // Use std::random_device for non-deterministic seeding  
  std::random_device rd_;                     
  // ranlux48 generator  
  std::ranlux48_base gen_; // Generator
  // Create a uniform int64 distribution for the desired range
  std::uniform_int_distribution<int64_t> dist_; 
};

// example usage
int main() {
  RandomInt64Gen generator;
  int64_t random_value = generator(-1000, 1000); // min & max
  std::cout << "Your Random Number is -> " << random_value << '\n';

  return 0;
}

