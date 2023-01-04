#include <iostream>
bool CheckPol(char* begin, char* end) {
  for (int i = 0; i <= (end - begin) / 2; i++) {
    if (begin[i] != begin[end - begin - i - 1]) {
      return false;
    }
  }
  return true;
}
int main() {
  std::ios::sync_with_stdio(false);
  int counter = 0;
  auto string_to_check = new char[10000000];
  while (std::cin) {
    std::cin >> string_to_check[counter];
    counter++;
  }
  auto* string_letter = new char[counter];
  int new_counter = 0;
  for (int i = 0; i < counter; ++i) {
    if (((static_cast<int>(string_to_check[i]) >= static_cast<int>('A')) &&
         (static_cast<int>(string_to_check[i]) <= static_cast<int>('Z'))) ||
        ((static_cast<int>(string_to_check[i]) >= static_cast<int>('a')) &&
         (static_cast<int>(string_to_check[i]) <= static_cast<int>('z')))) {
      if (static_cast<int>(string_to_check[i]) >= static_cast<int>('a')) {
        string_letter[new_counter] = char(static_cast<int>(string_to_check[i]) - 32);
      } else {
        string_letter[new_counter] = string_to_check[i];
      }
      new_counter++;
    }
  }
  if (new_counter == 0) {
    std::cout << "NO";
    delete[] string_letter;
    delete[] string_to_check;
    return 0;
  }
  if (CheckPol(string_letter, string_letter + new_counter)) {
    std::cout << "YES" << '\n';
    for (int j = 0; j < new_counter; j++) {
      std::cout << string_letter[j];
    }
    delete[] string_letter;
    delete[] string_to_check;
    return 0;
  }
  for (int i = 0; i < new_counter; i++) {
    if (string_letter[i] != string_letter[new_counter - i - 1]) {
      if (CheckPol(string_letter + i + 1, string_letter + new_counter - i - 1)) {
        std::cout << "YES" << '\n';
        for (int j = 0; j < new_counter; j++) {
          if (j != i) {
            std::cout << string_letter[j];
          } else {
            std::cout << string_letter[new_counter - i - 1];
          }
        }
        delete[] string_letter;
        delete[] string_to_check;
        return 0;
      }
      if (CheckPol(string_letter + i, string_letter + new_counter - i - 1)) {
        std::cout << "YES" << '\n';
        for (int j = 0; j < new_counter; j++) {
          if (j != new_counter - i - 1) {
            std::cout << string_letter[j];
          }
        }
        delete[] string_letter;
        delete[] string_to_check;
        return 0;
      }
      if (CheckPol(string_letter + i, string_letter + new_counter - i + 1)) {
        std::cout << "YES" << '\n';
        for (int j = 0; j < new_counter; j++) {
          if (j != i) {
            std::cout << string_letter[j];
          }
        }
        delete[] string_letter;
        delete[] string_to_check;
        return 0;
      }
      std::cout << "NO";
      delete[] string_letter;
      delete[] string_to_check;
      return 0;
    }
  }
}