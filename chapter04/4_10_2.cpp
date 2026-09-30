#include <iostream>

int main(int argc, char *argv[]) {
  int x{};
  std::cout << "Please enter a number between 0 and 9: \n";
  std::cin >> x;

  if (x >= 0 && x <= 9) {
    if (x == 2 || x == 3 || x == 5 || x == 7) {
      std::cout << "This digit is prime.\n";
    } else {
      std::cout << "This digit is not prime.\n";
    }
  } else {
    std::cout << "This number is out of range, please try again.\n";
  }

  return 0;
}
