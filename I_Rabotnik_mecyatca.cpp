#include <iostream>
template <class T>
T& Max(T& a, T& b) {
  return ((a > b) ? a : b);
}
template <class T>
T& Min(T& a, T& b) {
  return ((a > b) ? b : a);
}
int64_t BinarySearch(int64_t w, int64_t h, int64_t n) {
  int64_t left = Min(w, h);
  int64_t right = Max(w, h) * n;
  int64_t middle;
  while (left < right - 1) {
    middle = (left + right) / 2;
    int64_t cur_n = (middle / w) * (middle / h);
    if (cur_n >= n) {
      right = middle;
    } else {
      left = middle;
    }
  }
  return right;
}
int main() {
  int64_t n;
  int64_t w;
  int64_t h;
  std::cin >> w >> h >> n;
  std::cout << BinarySearch(w, h, n);
  return 0;
}