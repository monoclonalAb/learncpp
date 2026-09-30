#include <iostream>

double calculation(double first, double second, char operation) {
  if (operation == '+') {
    return first + second;
  } else if (operation == '-') {
    return first - second;
  } else if (operation == '*') {
    return first * second;
  } else if (operation == '/') {
    return first / second;
  }
  return 0.0;
}

int main() {
  std::cout << "Enter a double value: ";

  double first{};
  std::cin >> first;

  std::cout << "Enter a double value: ";

  double second{};
  std::cin >> second;

  std::cout << "Enter +, -, *, or /: ";

  char operation{};
  std::cin >> operation;

  std::cout << first << " " << operation << " " << second << " is "
            << calculation(first, second, operation) << '\n';
}
