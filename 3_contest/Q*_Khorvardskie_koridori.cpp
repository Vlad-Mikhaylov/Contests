#include <iostream>

int main() {
  int x;
  int y;
  std::cin >> x >> y;
  int w;
  int h;
  std::cin >> h >> w;
  auto floor = new int*[x];
  for (int i = 0; i < x; i++) {
    floor[i] = new int[y]{};
    for (int j = 0; j < y; j++) {
      std::cin >> floor[i][j];
    }
  }
  int cur_pos_x = 0;
  int cur_pos_y = 0;
  int cur_pos_x_max = 0;
  int cur_pos_y_max = 0;
  do {
    cur_pos_x = cur_pos_x_max;
    cur_pos_y = cur_pos_y_max;
    int max = -10;
    for (int i = cur_pos_x; i < cur_pos_x + h && i < x; i++) {
      for (int j = cur_pos_y; j < cur_pos_y + w && j < y; j++) {
        if (floor[i][j] > max) {
          max = floor[i][j];
          cur_pos_x_max = i;
          cur_pos_y_max = j;
        }
      }
    }
  } while (cur_pos_x != cur_pos_x_max || cur_pos_y != cur_pos_y_max);
  std::cout << cur_pos_x << " " << cur_pos_y;
  for (int i = 0; i < x; i++) {
    delete[] floor[i];
  }
  delete[] floor;
}