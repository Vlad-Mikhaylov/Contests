#include "O*BinSearch.h"
#include <iostream>

int main() {
  int n, k, l, m;
  std::cin >> n;
  auto array_n = new int64_t[n];
  for (int i = 0; i < n; ++i) {
     std::cin >> array_n[i];
  }
  std::cin >> array_n[k];
  std::cin >> array_n[l];
  std::cin >> array_n[m];
  std::cout << BinarySearch(array); // false

  std::cout << *(LowerBound(array + 1, array + 5, 3)); // указатель на 2й элемент

  std::cout << *(UpperBound(array, array + 2, 4)); // указатель на 2й элемент (на [0, 2) такого элемента нет)
  return 0;
}