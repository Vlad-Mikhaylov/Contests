#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int64_t s_1 = 1;
  int64_t s_2 = 1;
  int64_t tmp;
  for (int i = 1; i <= n; i++) {
    tmp = s_1;
    s_1 = s_1 + s_2;
    s_2 = tmp;
  }
  std::cout << s_1;
  return 0;
}