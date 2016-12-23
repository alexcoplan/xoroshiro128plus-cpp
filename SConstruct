flags = '-std=c++11 -Wall -pedantic -g -fcolor-diagnostics -DDEBUG'
env = Environment(CXX='clang++', CXXFLAGS=flags, CPPPATH = ['.'])

env.Program(target = 'rand_reals.out', source = ["example/rand_reals.cpp",
"xoroshiro.cpp"])
