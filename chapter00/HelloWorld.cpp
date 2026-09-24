#include <iostream>

// compiling -> g++ -o HelloWorld HelloWorld.cpp

int main() {
  std::cout << "Hello world!";
  return 0;
}

/*
 * # bunch of compiler flags for gcc
 *
 * debug builds => -ggdb
 * release builds => -02 -DNDEBUG
 *
 * -0# is used to control optimisations
 *
 * -00 recommended for debug (disables optimisations)
 * -02 recommended for release (applies optimisations)
 * -03 adds additional optimisations (might not be better than -02; you have to
 * test it out)
 *
 * compiler extensions get disabled from `-pedantic-errors`
 *
 * to increase warning levels `Wall -Weffc++ -Wextra -Wconversion
 * -Wsign-conversion`
 *
 * to support different language standards: -std=c++11, -std=c++14, -std=c++17,
 * -std=c++20, or -std=c++23
 * */
