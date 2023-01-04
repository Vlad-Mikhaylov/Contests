#include <iostream>
void Delete(int* array) {
  delete[] array;
}
void CountCoins(int* coins, int* tmp_res, int* res, int summ, int m, int idx, int& min_amount, int64_t curr_summ,
                int curr_amount) {
  if (idx == m - 1) {
    if (curr_summ == summ && curr_amount < min_amount) {
      min_amount = curr_amount;
      std::copy(tmp_res, tmp_res + m, res);
    }
    return;
  }
  for (int i = 0; i < 3; ++i) {
    tmp_res[idx + 1] = i;
    CountCoins(coins, tmp_res, res, summ, m, idx + 1, min_amount, curr_summ + i * coins[idx + 1], curr_amount + i);
  }
}
int main() {
  int n;
  int m;
  std::cin >> n >> m;
  int min_amount = 99999;
  auto coins = new int[m];
  auto tmp_res = new int[m];
  auto res = new int[m];
  int64_t sigma = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> coins[i];
    sigma += coins[i];
  }
  if (n > 2 * sigma) {
    std::cout << "-1";
    Delete(coins);
    Delete(res);
    Delete(tmp_res);
    return 0;
  }
  CountCoins(coins, tmp_res, res, n, m, -1, min_amount, 0, 0);
  if (min_amount == 99999) {
    std::cout << "0";
    Delete(coins);
    Delete(res);
    Delete(tmp_res);
    return 0;
  }
  std::cout << min_amount << '\n';
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < res[j]; i++) {
      std::cout << coins[j] << ' ';
    }
  }
  Delete(coins);
  Delete(res);
  Delete(tmp_res);
  return 0;
}