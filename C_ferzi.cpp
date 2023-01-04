#include <iostream>
void Delete(bool* array) {
  delete[] array;
}
void Search(int ry, int& rcounter, bool* column, bool* diag_right, bool* diag_left, int n) {
  if (ry == n) {
    ++rcounter;
    return;
  }
  for (int x = 0; x < n; x++) {
    if (column[x] || diag_right[2 + x + ry] || diag_left[2 + x - ry + n - 1]) {
      continue;
    }
    column[x] = true;
    diag_right[2 + x + ry] = true;
    diag_left[2 + x - ry + n - 1] = true;
    Search(ry + 1, rcounter, column, diag_right, diag_left, n);
    column[x] = false;
    diag_right[2 + x + ry] = false;
    diag_left[2 + x - ry + n - 1] = false;
  }
}
int main() {
  int n;
  std::cin >> n;
  if (n == 0) {
    std::cout << 1;
  } else {
    int counter = 0;
    auto column = new bool[n + 1]{};
    auto diag_right = new bool[2 * n + 2]{};
    auto diag_left = new bool[2 * n + 2]{};
    Search(0, counter, column, diag_right, diag_left, n);
    std::cout << counter;
    Delete(column);
    Delete(diag_right);
    Delete(diag_left);
  }
  return 0;
}
