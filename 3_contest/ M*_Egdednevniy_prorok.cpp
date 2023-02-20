#include <iostream>
#include <cstring>

int main() {
  auto string_to_convert = new char[5001];
  auto string_res = new char[5001];
  std::cin >> string_to_convert >> string_res;
  int counter_1 = std::strlen(string_to_convert);
  int counter_2 = std::strlen(string_res);
  auto dp = new int*[counter_1 + 1];
  for (int i = 0; i < counter_1 + 1; i++) {
    dp[i] = new int[counter_2 + 1];
  }
  for (int i = 0; i < counter_2 + 1; i++) {
    dp[0][i] = i;
  }
  for (int i = 1; i < counter_1 + 1; i++) {
    dp[i][0] = i;
  }
  for (int i = 1; i < counter_1 + 1; i++) {
    for (int j = 1; j < counter_2 + 1; j++) {
      dp[i][j] = std::min(std::min(dp[i][j - 1] + 1, dp[i - 1][j] + 1),
                          dp[i - 1][j - 1] + 1 * (string_res[j - 1] != string_to_convert[i - 1]));
    }
  }
  std::cout << dp[counter_1][counter_2];
  for (int i = 0; i < counter_1 + 1; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  delete[] string_res;
  delete[] string_to_convert;
  return 0;
}