#include <iostream>

int main() {
  int n;
  std::cin >> n;
  auto** box_sizes = new int*[n];
  int64_t height = 0;
  for (int i = 0; i < n; i++) {
    box_sizes[i] = new int[2];
    std::cin >> box_sizes[i][0] >> box_sizes[i][1];
    height += std::max(box_sizes[i][0], box_sizes[i][1]);
  }
  std::cout << height;
  for (int i = 0; i < n; i++) {
    delete[] box_sizes[i];
  }
  delete[] box_sizes;
  return 0;
}