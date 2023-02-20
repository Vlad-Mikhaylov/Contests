#include <iostream>
#include <algorithm>
#include <limits>

int main() {
  const int infinity = std::numeric_limits<int>::max();
  int n;
  std::cin >> n;
  auto list_1 = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> list_1[i];
  }
  auto delta = new int[n + 1];
  for (int i = 0; i < n + 1; i++) {
    delta[i] = i;
  }
  auto position = new int[n + 1];
  for (int i = 0; i < n + 1; i++) {
    position[i] = i;
  }
  auto prev = new int[n];
  for (int i = 0; i < n; i++) {
    prev[i] = i;
  }
  int length = 0;
  position[0] = -1;
  delta[0] = -1 * infinity;
  for (int i = 1; i < n + 1; i++) {
    delta[i] = infinity;
  }
  for (int i = 0; i < n; i++) {
    int j = std::lower_bound(delta, delta + n + 1, list_1[i]) - delta;
    if ((delta[j - 1] <= list_1[i]) && (list_1[i] <= delta[j])) {
      delta[j] = list_1[i];
      position[j] = i;
      prev[i] = position[j - 1];
      length = std::max(length, j);
    }
  }
  /* auto subseq = new int[length + 1];
  int pos = position[length];
  int i = 0;
  while (pos != -1) {
    subseq[i] = list_1[pos];
    pos = prev[pos];
    ++i;
  }
  for (int j = i - 1; j >= 0; --j) {
    std::cout << subseq[j] << ' ';
  }
  delete[] subseq; */
  std::cout << length;
  delete[] delta;
  delete[] list_1;
  delete[] position;
  delete[] prev;
  return 0;
}