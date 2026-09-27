#include <iostream>

int readNumber() {
  int x{};
  std::cin >> x;
  return x;
}

void writeAnswer(int answer) { std::cout << answer; }

int main() {
  int first{readNumber()};
  int second{readNumber()};

  writeAnswer(first + second);

  return 0;
}
