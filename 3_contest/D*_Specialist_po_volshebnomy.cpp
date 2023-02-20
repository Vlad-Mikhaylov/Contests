#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int64_t s_1 = 1;
  int64_t s_2 = 1;
  int64_t s_3 = 1;
  int64_t tmp_1;
  int64_t tmp_2;
  int64_t tmp_3;
  for (int i = 1; i <= n; i++) {
    tmp_1 = s_1;
    tmp_2 = s_2;
    tmp_3 = s_3;
    s_1 = tmp_1 + tmp_2 + tmp_3;
    s_2 = tmp_1 + tmp_2 + tmp_3;
    s_3 = tmp_1 + tmp_2;
  }
  std::cout << tmp_1 + tmp_2 + tmp_3;
  return 0;
}