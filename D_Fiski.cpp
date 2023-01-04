#include <iostream>
void Paste(int k);
void Delete(int k);
void Delete(int k) { 
  if (k == 1) { 
    std:: cout << "-1";
    return;
  }
  Paste(k - 1);
  std::cout << '-' << k;
  Delete(k - 1);
}
void Paste(int k) {
  if (k == 0) {
    std::cout << 1;
    return;
  }
  Delete(k - 1);
  std::cout << k + 1;
}
int main() {
  int n;
  std::cin >> n;
  Paste(n);
  return 0;
}
