#include <iostream>
int main() {
  int64_t n;
  int64_t m;
  int64_t k;
  std::cin >> n >> m >> k;
  auto colors = new int64_t[k]{};
  int64_t b = ((n % k) >= (m % k) ? (n % k) : (m % k));
  int64_t a = (n % k) + (m % k) - b;
  for (int i = 0; i < k; i++) {
    colors[i] = k * (n / k) * (m / k) + (n % k) * (m / k) + (m % k) * (n / k);
  }
  for (int i = 0; i < a + b - 1; i++) {
    colors[i] += (i + 1 <= a) * (i + 1) + (a + b - i - 1) * (i + 1 >= b) + (b > i + 1 && i + 1 > a) * a - 1;
  }
  for (int l = 0; l < k; l++) {
    std::cout << colors[l] << ' ';
  }
  delete[] colors;
  return 0;
}