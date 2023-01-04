#include <iostream>
void Merge(int* array, int left, int mid, int right);
void Sort(int* array, int left, int right);
int main() {
  int n;
  std::cin >> n;
  auto list_lines = new int[n + 1];
  list_lines[n] = 100000;
  for (int i = 0; i < n; i++) {
    std::cin >> list_lines[i];
  }
  if (n == 0) {
    std::cout << n << ' ' << n;
    delete[] list_lines;
    return 0;
  }
  if (n == 1) {
    std::cout << n << ' ' << list_lines[0];
    delete[] list_lines;
    return 0;
  }
  if (n == 2) {
    std::cout << n << ' ' << list_lines[0] + list_lines[1];
    delete[] list_lines;
    return 0;
  }
  Sort(list_lines, 0, n);
  int i = 0;
  int j = 2;
  int64_t sum = list_lines[0] + list_lines[1];
  int max_sum_length = 1;
  int64_t max_sum = sum;
  while (j <= n - 1 && j > i + 1) {
    while (list_lines[i] + list_lines[i + 1] >= list_lines[j]) {
      sum += list_lines[j];
      if (sum > max_sum) {
        max_sum = sum;
        max_sum_length = j - i + 1;
      }
      j++;
    }
    while (list_lines[i] + list_lines[i + 1] < list_lines[j]) {
      sum -= list_lines[i];
      i++;
    }
  }
  if (max_sum <= list_lines[n - 2] + list_lines[n - 1]) {
    std::cout << 2 << ' ' << list_lines[n - 2] + list_lines[n - 1];
    delete[] list_lines;
    return 0;
  }
  std::cout << max_sum_length << ' ' << max_sum;
  delete[] list_lines;
  return 0;
}

void Merge(int* array, int left, int mid, int right) {
  int i = 0;
  int j = 0;
  auto result = new int[right - left];
  while ((left + i < mid) && (mid + j < right)) {
    if (array[left + i] <= array[mid + j]) {
      result[i + j] = array[left + i];
      i++;
    } else {
      result[i + j] = array[mid + j];
      j++;
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
  for (int l = 0; l < i + j; l++) {
    array[left + l] = result[l];
  }
  delete[] result;
}

void Sort(int* array, int left, int right) {
  if (left + 1 >= right) {
    return;
  }
  int mid = (left + right) / 2;
  Sort(array, left, mid);
  Sort(array, mid, right);
  Merge(array, left, mid, right);
}