#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int64_t s_0 = 0;
  int64_t s_1 = 1;
  int64_t s_2 = 1;
  int64_t s_3 = 1;
  int64_t s_4 = 1;
  int64_t s_5 = 0;
  int64_t s_6 = 1;
  int64_t s_7 = 1;
  int64_t s_8 = 0;
  int64_t s_9 = 1;
  int64_t tmp_0;
  int64_t tmp_1;
  int64_t tmp_2;
  int64_t tmp_3;
  int64_t tmp_4;
  int64_t tmp_5;
  int64_t tmp_6;
  int64_t tmp_7;
  int64_t tmp_8;
  int64_t tmp_9;
  for (int i = 1; i <= n; i++) {
    tmp_0 = s_0;
    tmp_1 = s_1;
    tmp_2 = s_2;
    tmp_3 = s_3;
    tmp_4 = s_4;
    tmp_5 = s_5;
    tmp_6 = s_6;
    tmp_7 = s_7;
    tmp_8 = s_8;
    tmp_9 = s_9;
    s_0 = tmp_4 + tmp_6;
    s_1 = tmp_6 + tmp_8;
    s_2 = tmp_9 + tmp_7;
    s_3 = tmp_4 + tmp_8;
    s_4 = tmp_9 + tmp_3 + tmp_0;
    s_5 = 0;
    s_6 = tmp_1 + tmp_7 + tmp_0;
    s_7 = tmp_2 + tmp_6;
    s_8 = tmp_1 + tmp_3;
    s_9 = tmp_4 + tmp_2;
  }
  if (n == 1) {
    std::cout << 8;
  } else {
    std::cout << tmp_0 + tmp_1 + tmp_2 + tmp_3 + tmp_4 + tmp_5 + tmp_6 + tmp_7 + tmp_8 + tmp_9;
  }
  return 0;
}