#include <iostream>
#include <random>
#include <array>

#include "xoroshiro.hpp"

int main(void) {
  xoroshiro128plus_engine eng;

  std::random_device dev{};
  eng.seed([&dev]() { return dev(); });

  std::uniform_real_distribution<> dist(0.0, 1.0);

  for (int i = 0; i < 20; i++)
    std::cout << dist(eng) << std::endl;
}


