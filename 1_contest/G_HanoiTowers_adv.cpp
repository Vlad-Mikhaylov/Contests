#include <iostream>
int HanoiMove(int n, int previous, int following) {
  std::cout << n << ' ' << previous << ' ' << following << '\n';
  return 0;
}
void Hanoi(int n, int previous, int following) {
  if (n == 1) {
    HanoiMove(1, previous, following);
  } else {
    int tmp = 6 - previous - following;
    Hanoi(n - 1, previous, following);
    HanoiMove(n, previous, tmp);
    Hanoi(n - 1, following, previous);
    HanoiMove(n, tmp, following);
    Hanoi(n - 1, previous, following);
  }
}
int main() {
  int n = 0;
  int previous = 1;
  int following = 3;
  std::cin >> n;
  Hanoi(n, previous, following);
  return 0;
}
