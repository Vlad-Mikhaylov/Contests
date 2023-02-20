#include <iostream>
#include <limits>

int Count(int** dp, int* matrix_list, int i, int j) {
  if (dp[i][j] != std::numeric_limits<int>::max()) {
    return dp[i][j];
  }
  if (i == j) {
    dp[i][j] = 0;
    return 0;
  }
  for (int k = i; k < j; k++) {
    dp[i][j] = std::min(dp[i][j], Count(dp, matrix_list, i, k) + Count(dp, matrix_list, k + 1, j) +
                                      matrix_list[i] * matrix_list[k + 1] * matrix_list[j + 1]);
  }
  return dp[i][j];
}
int main() {
  int n;
  std::cin >> n;
  auto list_matrix = new int[n];
  auto dp = new int*[n - 1];
  for (int i = 0; i < n; i++) {
    std::cin >> list_matrix[i];
  }
  for (int i = 0; i < n - 1; i++) {
    dp[i] = new int[n - 1];
    for (int j = 0; j < n - 1; j++) {
      dp[i][j] = std::numeric_limits<int>::max();
    }
  }
  std::cout << Count(dp, list_matrix, 0, n - 2);
  for (int i = 0; i < n - 1; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  delete[] list_matrix;
}