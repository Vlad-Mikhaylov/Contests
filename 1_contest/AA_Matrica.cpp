#include <iostream>

void Delete(int** array, int n) {
  for (int i = 0; i < n; ++i) {
    delete[] array[i];
  }
  delete[] array;
}
int main() {
  int n;
  std::cin >> n;
  auto matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> matrix[i][j];
    }
  }
  auto minimal_val = new int[n];
  for (int i = 0; i < n; i++) {
    minimal_val[i] = 1001;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (((matrix[j][i] <= 0) && (i != j)) || ((i == j) && (matrix[i][j] != 0))) {
        std::cout << "-1";
        Delete(matrix, n);
        delete[] minimal_val;
        return 0;
      }
      if ((i != j) && (matrix[j][i] < minimal_val[j])) {
        minimal_val[j] = matrix[j][i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i != j) && (matrix[i][j] != (minimal_val[i] > minimal_val[j] ? minimal_val[i] : minimal_val[j]))) {
        std::cout << "-1";
        Delete(matrix, n);
        delete[] minimal_val;
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << minimal_val[i] << ' ';
  }
  Delete(matrix, n);
  delete[] minimal_val;
  return 0;
}