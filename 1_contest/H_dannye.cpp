#include <iostream>
int main() {
  int end;
  char input_data[10000];
  for (int i = 0; i <= 10000; i++) {
    std::cin >> input_data[i];
    if (input_data[i] == '#') {
      end = i - 1;
      break;
    }
  }
  auto* new_key = new char[end + 1];
  for (int i = 0; i <= end; i++) {
    if (i % 2 == 0) {
      new_key[i / 2] = input_data[i];
    } else {
      new_key[end - i / 2] = input_data[i];
    }
  }
  for (int i = 0; i <= end; i++) {
    std::cout << new_key[i];
  }
  delete[] new_key;
  return 0;
}