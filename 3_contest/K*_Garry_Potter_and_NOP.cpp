#include <iostream>
#include <cstring>
struct Pair {
  int i;
  int j;
};
void PrintLCS(int i, int j, Pair** prev, int* list_1) {
  if (i == 0 || j == 0) {
    return;
  }
  if ((prev[i][j].j == j - 1) && (prev[i][j].i == i - 1)) {
    PrintLCS(i - 1, j - 1, prev, list_1);
    std::cout << list_1[i] << ' ';
  } else {
    if ((prev[i][j].j == j) && (prev[i][j].i == i - 1)) {
      PrintLCS(i - 1, j, prev, list_1);
    } else {
      PrintLCS(i, j - 1, prev, list_1);
    }
  }
}
int main() {
  int m;
  int n;
  std::cin >> m;
  auto list_1 = new int[m + 1];
  for (int i = 1; i < m + 1; i++) {
    std::cin >> list_1[i];
  }
  for (int i = 0; i < m + 1; i++) {
    std::cout << list_1[i] << ' ';
  }
  std::cin >> n;
  auto list_2 = new int[n + 1];
  for (int i = 1; i < n + 1; i++) {
    std::cin >> list_2[i];
  }
  for (int i = 0; i < n + 1; i++) {
    std::cout << list_2[i] << ' ';
  }
  auto dp = new int*[m + 1];
  for (int i = 0; i < m + 1; i++) {
    dp[i] = new int[n + 1];
  }
  auto prev = new Pair*[m + 1];
  for (int i = 0; i < m + 1; i++) {
    prev[i] = new Pair[n + 1];
  }
  for (int i = 0; i < n + 1; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i < m + 1; i++) {
    dp[i][0] = 0;
  }
  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (list_1[i] == list_2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        prev[i][j].j = j - 1;
        prev[i][j].i = i - 1;
      } else {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
          prev[i][j].j = j;
          prev[i][j].i = i - 1;
        } else {
          dp[i][j] = dp[i][j - 1];
          prev[i][j].i = i;
          prev[i][j].j = j - 1;
        }
      }
    }
  }
  PrintLCS(m, n, prev, list_1);
  for (int i = 0; i < m + 1; i++) {
    delete[] dp[i];
  }
  for (int i = 0; i < m + 1; i++) {
    delete[] prev[i];
  }
  delete[] dp;
  delete[] prev;
  delete[] list_1;
  delete[] list_2;
  return 0;
}