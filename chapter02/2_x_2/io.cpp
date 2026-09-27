#include <iostream>

int readNumber() {
  int x{};
  std::cin >> x;
  return x;
}

void writeAnswer(int answer) { std::cout << answer; }
