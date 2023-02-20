#include <iostream>
int main() {
  int k;
  std::cin >> k;
  int counter = 0;
  auto input_str = new char[1000000];
  while (std::cin) {
    std::cin >> input_str[counter];
    counter++;
  }
  int n = counter;
  counter = 0;
  int res = 0;
  for (int i = 0; i < n - k - 1; i++) {
    if (input_str[i] == input_str[i + k]) {
      counter++;
    } else {
      counter = 0;
    }
    res += counter;
  }
  std::cout << res;
  delete[] input_str;
  return 0;
}