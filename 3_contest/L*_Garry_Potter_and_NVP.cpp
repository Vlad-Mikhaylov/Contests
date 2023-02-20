#include <iostream>

int main() {
  int n;
  int amount = 0;
  std::cin >> n;
  auto dp = new int[n];
  auto list_num = new int[10000];
  for (int i = 0; i < 5000; i++) {
    list_num[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> dp[i];
  }
  for (int i = 0; i < n; i++) {
    list_num[dp[i]] += 1;
    for (int j = 0; j < dp[i]; j++) {
      list_num[dp[i]] += list_num[j];
    }
    list_num[dp[i]] = list_num[dp[i]] % 1000000;
  }
  for (int i = 0; i < 5000; i++) {
    amount = amount + list_num[i];
  }
  std::cout << (amount % 1000000);
  delete[] dp;
  delete[] list_num;
  return 0;
}