#include <iostream>

int main() {
  std::cout << "Enter the height of the tower in meters: ";

  int time{0};
  double towerHeight{};
  std::cin >> towerHeight;

  double height{towerHeight};

  while (height > 0.0) {
    std::cout << "At " << time << " seconds, the ball is at height: " << height
              << " meters\n";

    height = towerHeight - 9.8 * pow(time + 1, 2) / 2.0;
    ++time;
  }

  std::cout << "At " << time << " seconds, the ball is on the ground.\n";

  return 0;
}
