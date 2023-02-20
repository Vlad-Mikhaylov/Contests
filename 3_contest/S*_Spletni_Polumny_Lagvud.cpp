#include <iostream>
#include <cstring>

int main() {
  auto lst = new char[20000];
  std::cin >> lst;
  auto m = static_cast<int>(std::strlen(lst));
  auto list_1 = new char[m + 1];
  list_1[0] = '\0';
  for (int i = 0; i < m; i++) {
    list_1[i + 1] = lst[i];
  }
  delete[] lst;
  auto list_2 = new char[m + 1];
  list_2[0] = '\0';
  int t = 1;
  for (int i = m; i > 0; i--) {
    list_2[t] = list_1[i];
    t++;
  }
  auto dp = new int*[m + 1];
  for (int i = 0; i < m + 1; i++) {
    dp[i] = new int[m + 1];
  }
  for (int i = 0; i < m + 1; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i < m + 1; i++) {
    dp[i][0] = 0;
  }
  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      dp[i][j] = (list_1[i] == list_2[j]) ? dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  std::cout << m - dp[m][m];
  delete[] list_2;
  for (int i = 0; i < m + 1; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  delete[] list_1;
  return 0;
}