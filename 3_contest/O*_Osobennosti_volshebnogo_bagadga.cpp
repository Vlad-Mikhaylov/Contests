#include <iostream>
void BackPack(int** a, int* w, int k, int s) {
  if (a[k][s] <= 0) {
    return;
  }
  if (a[k - 1][s] == a[k][s]) {
    BackPack(a, w, k - 1, s);
  } else {
    BackPack(a, w, k - 1, s - w[k]);
    std::cout << k << '\n';
  }
}
int main() {
  int n;
  int m;
  std::cin >> n >> m;
  auto mass = new int[n + 1];
  auto price = new int[n + 1];
  for (int i = 1; i < n + 1; i++) {
    std::cin >> mass[i];
  }
  for (int i = 1; i < n + 1; i++) {
    std::cin >> price[i];
  }
  auto dp = new int*[n + 1];
  for (int i = 0; i < n + 1; i++) {
    dp[i] = new int[m + 1];
  }
  for (int i = 0; i < m + 1; i++) {
    dp[0][i] = 0;
  }
  for (int i = 0; i < n + 1; i++) {
    dp[i][0] = 0;
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (j >= mass[i] && (dp[i - 1][j - mass[i]] + price[i] > dp[i - 1][j])) {
        dp[i][j] = dp[i - 1][j - mass[i]] + price[i];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  BackPack(dp, mass, n, m);
  delete[] mass;
  delete[] price;
  for (int i = 0; i < n + 1; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}