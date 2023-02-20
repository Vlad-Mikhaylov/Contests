#include <iostream>
#include <algorithm>

struct Report {
  int index;
  int value;
};

void SiftDown(int* begin, int* end, int i, Report& output) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;
  if ((left < end - begin) && (begin[largest] < begin[left])) {
    largest = left;
  }
  if ((right < end - begin) && (begin[largest] < begin[right])) {
    largest = right;
  }
  if (largest != i) {
    std::swap(begin[i], begin[largest]);
    SiftDown(begin, end, largest, output);
  } else {
    output.index = i;
  }
}

void SiftUp(int* begin, int* end, int i, Report& output) {
  int parent = (i - 1) / 2;
  if (i > 0) {
    if (begin[i] > begin[parent]) {
      std::swap(begin[i], begin[parent]);
      SiftUp(begin, end, parent, output);
    } else {
      output.index = i;
    }
  } else {
    output.index = i;
  }
}

Report TakeMax(int* begin, int* end) {
  Report output;
  if (end - begin == 0) {
    output.index = -1;
    return output;
  }
  if (end - begin == 1) {
    output.index = -1;
    output.value = begin[0];
    return output;
  }
  if (end - begin == 2) {
    output.index = 0;
    output.value = begin[0];
    std::swap(begin[0], begin[1]);
    return output;
  }
  output.value = begin[0];
  std::swap(begin[0], begin[end - begin - 1]);
  SiftDown(begin, end - 1, 0, output);
  return output;
}

int Insert(int* begin, int* end, int element) {
  Report output;
  begin[end - begin] = element;
  SiftUp(begin, end, end - begin, output);
  return output.index;
}

Report Delete(int* begin, int* end, int i) {
  Report output;
  if (i > end - begin || i < 1) {
    output.index = -1;
    return output;
  }
  if (end - begin == 1) {
    output.value = begin[0];
    return output;
  }
  i--;
  output.value = begin[i];
  std::swap(begin[i], begin[end - begin - 1]);
  SiftUp(begin, end - 1, i, output);
  SiftDown(begin, end - 1, output.index, output);
  return output;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  int m;
  std::cin >> n >> m;
  int cur_len = 0;
  int operation;
  int parametr;
  auto heap = new int[n + 1];
  Report output;
  for (int j = 0; j < m; j++) {
    std::cin >> operation;
    if (operation == 1) {
      if (cur_len == 0) {
        std::cout << -1 << '\n';
      } else {
        output = TakeMax(heap, heap + cur_len);
        std::cout << output.index + 1 << ' ' << output.value << '\n';
        cur_len--;
      }
    } else if (operation == 2) {
      std::cin >> parametr;
      if (cur_len >= n) {
        std::cout << -1 << '\n';
      } else {
        output.index = Insert(heap, heap + cur_len, parametr);
        cur_len++;
        std::cout << output.index + 1 << '\n';
      }
    } else if (operation == 3) {
      std::cin >> parametr;
      output = Delete(heap, heap + cur_len, parametr);
      if (output.index == -1) {
        std::cout << -1 << '\n';
      } else {
        std::cout << output.value << '\n';
        cur_len--;
      }
    }
  }
  for (int i = 0; i < cur_len; i++) {
    std::cout << heap[i] << ' ';
  }
  delete[] heap;
  return 0;
}