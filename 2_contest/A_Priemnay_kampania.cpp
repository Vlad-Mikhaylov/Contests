#include <iostream>
#include <cstring>
#include <algorithm>
struct Raiting {
  int points;
  char name[40];
  char surname[40];
};
bool Compare(Raiting one, Raiting two) {
  return one.points > two.points;
}
int main() {
  int n;
  std::cin >> n;
  auto id_and_result = new Raiting[n];
  int math;
  int rus;
  int inf;
  int i = 0;
  while (std::cin && i < n) {
    std::cin >> id_and_result[i].name >> id_and_result[i].surname;
    std::cin >> math >> inf >> rus;
    id_and_result[i].points = math + rus + inf;
    i++;
  }
  std::stable_sort(id_and_result, id_and_result + n, Compare);
  for (int i = 0; i < n; i++) {
    std::cout << id_and_result[i].name << ' ' << id_and_result[i].surname << '\n';
  }
  delete[] id_and_result;
  return 0;
}