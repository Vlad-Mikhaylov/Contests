#include <iostream>

int main() {
  int n;
  std::cin >> n;
  auto oper = new int[n + 1]{};
  for (int i = 2; i < n + 1; i++) {
    oper[i] = oper[i - 1] + 1;
    if (i % 6 == 0) {
      oper[i] = std::min(std::min(oper[i], 1 + oper[i / 2]), 1 + oper[i / 3]);
    } else {
      if (i % 2 == 0) {
        oper[i] = std::min(1 + oper[i / 2], oper[i]);
      }
      if (i % 3 == 0) {
        oper[i] = std::min(1 + oper[i / 3], oper[i]);
      }
    }
  }
  std::cout << oper[n];
  delete[] oper;
  return 0;
}