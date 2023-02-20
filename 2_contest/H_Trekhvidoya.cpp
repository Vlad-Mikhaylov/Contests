#include <iostream>

bool Check(char* string, int len) {
  auto stack_brackets = new char[len];
  int k = -1;
  int cnt_rnd = 0;
  int cnt_sqr = 0;
  int cnt_fig = 0;
  for (int i = 0; i < len; i++) {
    if (cnt_fig < 0 || cnt_rnd < 0 || cnt_sqr < 0) {
      delete[] stack_brackets;
      return false;
    }
    if (k == -1 && (string[i] == ')' || string[i] == '}' || string[i] == ']')) {
      delete[] stack_brackets;
      return false;
    }
    if (string[i] == '(') {
      k++;
      stack_brackets[k] = '(';
      cnt_rnd++;
      continue;
    }
    if (string[i] == ')') {
      cnt_rnd--;
      while (stack_brackets[k] == '\0' && k > 0) {
        k--;
      }
      if (k != -1) {
        if (stack_brackets[k] != '(') {
          delete[] stack_brackets;
          return false;
        }
      } else {
        delete[] stack_brackets;
        return false;
      }
      if (stack_brackets[k] == '(') {
        stack_brackets[k] = '\0';
      }
    }
    if (string[i] == '[') {
      k++;
      stack_brackets[k] = '[';
      cnt_sqr++;
      continue;
    }
    if (string[i] == ']') {
      cnt_sqr--;
      while (stack_brackets[k] == '\0' && k > 0) {
        k--;
      }
      if (k != -1) {
        if (stack_brackets[k] != '[') {
          delete[] stack_brackets;
          return false;
        }
      } else {
        delete[] stack_brackets;
        return false;
      }
      if (stack_brackets[k] == '[') {
        stack_brackets[k] = '\0';
      }
    }
    if (string[i] == '{') {
      k++;
      stack_brackets[k] = '{';
      cnt_fig++;
      continue;
    }
    if (string[i] == '}') {
      cnt_fig--;
      while (stack_brackets[k] == '\0' && k > 0) {
        k--;
      }
      if (k != -1) {
        if (stack_brackets[k] != '{') {
          delete[] stack_brackets;
          return false;
        }
      } else {
        delete[] stack_brackets;
        return false;
      }
      if (stack_brackets[k] == '{') {
        stack_brackets[k] = '\0';
      }
    }
  }
  delete[] stack_brackets;
  return ((cnt_fig == cnt_rnd) && (cnt_rnd == cnt_sqr) && (cnt_sqr == 0));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int len;
  int j = 0;
  auto string = new char[1000000];
  while (std::cin) {
    std::cin >> string[j];
    j++;
  }
  len = j;
  if (Check(string, len)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  delete[] string;
  return 0;
}