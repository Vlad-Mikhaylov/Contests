#include <iostream>
void Merge(int64_t* array, int64_t left, int64_t mid, int64_t right, int64_t& inv_counter) {
  int64_t i = 0;
  int64_t j = 0;
  auto result = new int64_t[right - left];
  while ((left + i < mid) && (mid + j < right)) {
    if (array[left + i] <= array[mid + j]) {
      result[i + j] = array[left + i];
      i++;
    } else {
      result[i + j] = array[mid + j];
      j++;
      inv_counter += mid - left - i;
    }
  }
  while (left + i < mid) {
    result[i + j] = array[left + i];
    i++;
  }
  while (mid + j < right) {
    result[i + j] = array[mid + j];
    j++;
  }
  for (int64_t l = 0; l < i + j; l++) {
    array[left + l] = result[l];
  }
  delete[] result;
}

void Sort(int64_t* array, int64_t left, int64_t right, int64_t& inv_counter) {
  if (left + 1 >= right) {
    return;
  }
  int64_t mid = (left + right) / 2;
  Sort(array, left, mid, inv_counter);
  Sort(array, mid, right, inv_counter);
  Merge(array, left, mid, right, inv_counter);
}
int main() {
  int64_t inv_counter = 0;
  int64_t n;
  std::cin >> n;
  auto array_n = new int64_t[n];
  for (int64_t i = 0; i < n; ++i) {
    std::cin >> array_n[i];
  }
  Sort(array_n, 0, n, inv_counter);
  std::cout << inv_counter;
  delete[] array_n;
  return 0;
}