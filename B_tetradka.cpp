#include <iostream>

void Delete(char** netbook, int n) {
  for (int i = 0; i < n; ++i) {
    delete[] netbook[i];
  }
  delete[] netbook;
}
int main() {
  int m;
  int n;
  std::cin >> n >> m;
  auto netbook = new char*[n];
  for (int i = 0; i < n; i++) {
    netbook[i] = new char[m];
    for (int j = 0; j < m; j++) {
      std::cin >> netbook[i][j];
    }
  }
  int count_lines = 0;
  int lines[2]{};
  int count_vert_lines = 0;
  int vert_lines[2]{};
  if ((n == 1) || (m == 1)) {
    std::cout << "?";
    Delete(netbook, n);
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if ((netbook[i][0] == '1') && (netbook[i][1] == '1')) {
      count_lines++;
      if (count_lines > 2) {
        break;
      }
      lines[count_lines - 1] = i;
    }
  }
  for (int j = 0; j < m; ++j) {
    if ((netbook[0][j] == '1') && (netbook[1][j] == '1')) {
      count_vert_lines++;
      if (count_vert_lines > 2) {
        break;
      }
      vert_lines[count_vert_lines - 1] = j;
    }
  }
  Delete(netbook, n);
  if (count_vert_lines * count_lines > 0) {
    std::cout << "Square";
    return 0;
  }
  if ((count_vert_lines == 0) && (count_lines > 1)) {
    if (lines[1] - lines[0] - 1 < m) {
      std::cout << "Line";
    } else {
      std::cout << "?";
    }
    return 0;
  }
  if (count_vert_lines > 1 && count_lines == 0) {
    if (vert_lines[1] - vert_lines[0] - 1 < n) {
      std::cout << "Vertical line";
    } else {
      std::cout << "?";
    }
    return 0;
  }
  std::cout << "?";
  return 0;
}