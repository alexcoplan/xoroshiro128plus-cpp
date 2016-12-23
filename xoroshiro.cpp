#include "xoroshiro.hpp"

/* C++11 UniformRandomBitGenerator wrapper around xoroshift128+.
 * Original C code from: http://xoroshiro.di.unimi.it/xoroshiro128plus.c */

xoroshiro128plus_engine::result_type
xoroshiro128plus_engine::operator()() {
  const uint64_t s0 = state[0];
  uint64_t s1 = state[1];
  const uint64_t result = s0 + s1;

  s1 ^= s0;
  state[0] = rotl(s0, 55) ^ s1 ^ (s1 << 14); // a, b
  state[1] = rotl(s1, 36); // c

  return result;
}

void xoroshiro128plus_engine::seed(std::function<uint32_t(void)> f) {
  uint64_t x_0 = f();
  uint64_t x_1 = f();
  state[0] = (x_0 << 32) | x_1;
  x_0 = f();
  x_1 = f();
  state[1] = (x_0 << 32) | x_1;
}

void xoroshiro128plus_engine::seed(const std::array<uint32_t, 4> &a) {
  state[0] = ((uint64_t)a[0] << 32) | (uint64_t)a[1];
  state[1] = ((uint64_t)a[2] << 32) | (uint64_t)a[3];
}

