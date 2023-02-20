#include <iostream>

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  auto dp = new int64_t[15][50];
  for (int i = 0; i < n; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 0; i < m; ++i) {
    dp[i][0] = 1;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      dp[j][i] = (dp[j - 1][i] + dp[j][i - 1] + dp[j - 1][i - 1]);
    }
  }
  std::cout << dp[m - 1][n - 1];
  delete[] dp;
  return 0;
}