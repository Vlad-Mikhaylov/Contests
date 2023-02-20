#include <iostream>
void Delete(int** array, int n) {
  for (int i = 0; i < n; ++i) {
    delete[] array[i];
  }
  delete[] array;
}
int Nieghbour(int** pre_array, int i, int j) {
  return ((pre_array[i - 1][j] != 0 ? 1 : 0) + (pre_array[i + 1][j] != 0 ? 1 : 0) + (pre_array[i][j - 1] != 0 ? 1 : 0) +
          (pre_array[i][j + 1] != 0 ? 1 : 0) + (pre_array[i - 1][j - 1] != 0 ? 1 : 0) +
          (pre_array[i + 1][j - 1] != 0 ? 1 : 0) + (pre_array[i - 1][j + 1] != 0 ? 1 : 0) +
          (pre_array[i + 1][j + 1] != 0 ? 1 : 0));
}
int main() {
  int neighbour;
  int n;
  int t;
  std::cin >> n;
  std::cin >> t;
  auto** array = new int*[n + 2];
  for (int i = 0; i <= n + 1; i++) {
    array[i] = new int[n + 2];
  }
  auto** pre_array = new int*[n + 2];
  for (int i = 0; i <= n + 1; i++) {
    pre_array[i] = new int[n + 2];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> array[i][j];
      pre_array[i][j] = 0;
    }
  }
  for (int j = 0; j <= n + 1; j++) {
    array[0][j] = 0;
    array[n + 1][j] = 0;
  }
  for (int j = 0; j <= n + 1; j++) {
    array[j][0] = 0;
    array[j][n + 1] = 0;
  }
  for (int j = 0; j <= n + 1; j++) {
    pre_array[0][j] = 0;
    pre_array[n + 1][j] = 0;
  }
  for (int j = 0; j <= n + 1; j++) {
    pre_array[j][0] = 0;
    pre_array[j][n + 1] = 0;
  }
  for (int time_counter = 1; time_counter <= t; time_counter++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        pre_array[i][j] = array[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        neighbour = Nieghbour(pre_array, i, j);
        if ((neighbour < 2) | (neighbour > 3)) {
          array[i][j] = 0;
        }
        if (neighbour == 3) {
          array[i][j] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << array[i][j] << ((j == n) ? "" : " ");
    }
    std::cout << '\n';
  }
  Delete(array, n + 2);
  Delete(pre_array, n + 2);
  return 0;
}