#include <iostream>
int Pow(int base, int k) {
  int tmp = 1;
  for (int i = 0; i < k; i++) {
    tmp = tmp * base;
  }
  return tmp;
}
int main() {
  int n;
  int m;
  int value = 0;
  bool check_list[4]{false};
  std::cin >> n >> m;
  int tmp = std::max(n, m);
  m = std::min(m, n);
  n = tmp;
  tmp = Pow(2, m);
  auto dp = new int*[n];
  for (int i = 0; i < n; i++) {
    dp[i] = new int[tmp]{};
  }
  for (int i = 0; i < tmp; i++) {
    dp[0][i] = 1;
  }
  if (m == 1) {
    std::cout << Pow(2, n);
  } else {
    int counter;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < tmp; j++) {
        for (int l = 0; l < tmp; l++) {
          bool checker = true;
          for (int k = 0; k < m - 1; k++) {
            counter = Pow(2, k);
            check_list[0] = (j & counter) >> k;
            check_list[1] = (j & (counter * 2)) >> (k + 1);
            check_list[2] = (l & counter) >> k;
            check_list[3] = (l & (counter * 2)) >> (k + 1);
            if (check_list[0] == check_list[1] && check_list[1] == check_list[2] && check_list[2] == check_list[3]) {
              checker = false;
              break;
            }
          }
          if (checker) {
            dp[i][j] = dp[i][j] + dp[i - 1][l];
          }
        }
      }
    }
    for (int j = 0; j < tmp; j++) {
      value = value + dp[n - 1][j];
    }
    std::cout << value;
  }
  for (int i = 0; i < n; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}