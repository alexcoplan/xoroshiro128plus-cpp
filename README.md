## Usage

This is a lightweight implementation of the
[xoroshiro128+](http://xoroshiro.di.unimi.it/) pseudo-random number generator in
the form of a C++11
[`UniformRandomBitGenerator`](http://en.cppreference.com/w/cpp/concept/UniformRandomBitGenerator).
This means that it can be used as a random number engine compatible with the
C++11 [`<random>`](http://en.cppreference.com/w/cpp/numeric/random) library. For example:

```
xoroshiro128plus_engine eng;

std::random_device dev{};
eng.seed([&dev]() { return dev(); });

std::uniform_real_distribution<> dist(0.0, 1.0);

dist(eng); // random double between 0 and 1
```

See
[here](https://github.com/alexcoplan/xoroshiro128plus-cpp/blob/master/example/rand_reals.cpp)
for a complete example.

## Compilation

To build the example code you will need the [SCons](http://www.scons.org/) build
system installed. You should find it via your favourite package manager.
