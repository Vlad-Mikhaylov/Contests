#include <iostream>
//
void Swap(int& arg_1, int& arg_2) {
  int64_t tmp = arg_1;
  arg_1 = arg_2;
  arg_2 = tmp;
}
// Partician Khoara
int64_t Partician(int64_t* array_point, int64_t left, int64_t right) {
  int64_t pivot = array_point[(left + right) / 2];
  int64_t i = left;
  int64_t j = right;
  while (i <= j) {
    while (array_point[i] < pivot) {
      ++i;
    }
    while (array_point[j] > pivot) {
      j--;
    }
    if (i >= j) {
      break;
    }
    std::swap(array_point[i++], array_point[j--]);
  }
  return j;
}
// QuickSort
void QuickSort(int64_t* array_point, int64_t left, int64_t right) {
  if (left >= right) {
    return;
  }
  int64_t pivot;
  pivot = Partician(array_point, left, right);
  QuickSort(array_point, left, pivot);
  QuickSort(array_point, pivot + 1, right);
}
//
int main() {
  int64_t n;
  std::cin >> n;
  auto array_n = new int64_t[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> array_n[i];
  }
  int64_t m;
  std::cin >> m;
  auto array_m = new int64_t[m];
  for (int i = 0; i < m; ++i) {
    std::cin >> array_m[i];
  }
  QuickSort(array_n, 0, n - 1);
  QuickSort(array_m, 0, m - 1);
  int64_t k = 0;
  int64_t l = 0;
  while ((k < m - 1) && (l < n - 1)) {
    while ((k + 1 < m - 1) & (array_m[k] == array_m[k + 1])) {
      k++;
    }
    while ((l + 1 < n - 1) & (array_n[l] == array_n[l + 1])) {
      l++;
    }
    if (array_n[l] == array_m[k]) {
      l += 1 * (l < n - 1);
      k += 1 * (k < m - 1);
    } else {
      std::cout << "NO";
      delete[] array_n;
      delete[] array_m;
      return 0;
    }
  }
  while (k < m - 1) {
    while ((k + 1 < m - 1) & (array_m[k] == array_m[k + 1])) {
      k++;
    }
    if (array_n[l] == array_m[k]) {
      k += 1 * (k < m - 1);
    } else {
      std::cout << "NO";
      delete[] array_n;
      delete[] array_m;
      return 0;
    }
  }
  while (l < n - 1) {
    while ((l + 1 < n - 1) & (array_n[l] == array_n[l + 1])) {
      l++;
    }
    if (array_n[l] == array_m[k]) {
      l += 1 * (l < n - 1);
    } else {
      std::cout << "NO";
      delete[] array_n;
      delete[] array_m;
      return 0;
    }
  }
  if (array_n[l] != array_m[k]) {
    std::cout << "NO";
    delete[] array_n;
    delete[] array_m;
    return 0;
  }
  std::cout << "YES";
  delete[] array_n;
  delete[] array_m;
  return 0;
}