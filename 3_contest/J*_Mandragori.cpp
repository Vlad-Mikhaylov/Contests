#include <iostream>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  auto manda = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> manda[i];
  }
  std::sort(manda, manda + n);
  int dp_cur;
  int dp_prev = manda[1] - manda[0];
  int dp_prev_prev = 10000000;
  for (int i = 2; i < n; i++) {
    dp_cur = std::min(dp_prev_prev + manda[i] - manda[i - 1], dp_prev + manda[i] - manda[i - 1]);
    dp_prev_prev = dp_prev;
    dp_prev = dp_cur;
  }
  n > 2 && std::cout << dp_cur;
  n == 2 && std::cout << manda[1] - manda[0];
  delete[] manda;
  return 0;
}