#include <iostream>
#include <algorithm>

struct FreqCards {
  int64_t frequency = 0;
  int64_t by_one = 0;
  int64_t by_two = 0;
  int64_t by_three = 0;
  void ByOne() {
    if (this->frequency > 2) {
      this->by_one = 1;
    } else {
      this->by_one = 0;
    }
  }
};

int main() {
  int n;
  int64_t k;
  std::cin >> n >> k;
  auto cards = new int64_t[n];
  for (int i = 0; i < n; i++) {
    std::cin >> cards[i];
  }
  if (n < 3) {
    std::cout << 0;
    delete[] cards;
    return 0;
  }
  std::sort(cards, cards + n);
  auto uniq_cards = new FreqCards[n];
  auto uniq_values = new int64_t[n];
  int j = 0;
  int l;
  for (int i = 0; i < n; i++) {
    uniq_values[j] = cards[i];
    uniq_cards[j].frequency++;
    while (i < n - 1 && cards[i] == cards[i + 1]) {
      uniq_cards[j].frequency++;
      i++;
    }
    uniq_cards[j].ByOne();
    j++;
    l = j;
  }
  if (n > 2 && cards[n - 1] == cards[n - 2]) {
    uniq_cards[l - 1].ByOne();
  }
  int64_t all_varients = 0;
  if (k == 1) {
    for (int i = 0; i < l; i++) {
      all_varients += uniq_cards[i].by_one;
    }
    std::cout << all_varients;
    delete[] uniq_cards;
    delete[] uniq_values;
    delete[] cards;
    return 0;
  }
  for (int j = 0; j < l; j++) {
    if (l != 1 && uniq_cards[j].frequency > 1) {
      int64_t range_two;
      range_two = std::upper_bound(uniq_values, uniq_values + l, uniq_values[j] * k) -
                  std::lower_bound(uniq_values, uniq_values + l, uniq_values[j] / k + (uniq_values[j] % k ? 1 : 0)) - 1;
      uniq_cards[j].by_two += (range_two > 0 ? (3 * range_two) : 0);
    }
  }
  for (int j = 0; j < l; j++) {
    if (l != 1) {
      int64_t range_three = std::upper_bound(uniq_values, uniq_values + l, uniq_values[j] * k) - uniq_values - j - 1;
      uniq_cards[j].by_three = (range_three * (range_three - 1)) * 3 > 0 ? (range_three * (range_three - 1)) * 3 : 0;
    }
  }
  for (int i = 0; i < l; i++) {
    all_varients += uniq_cards[i].by_one + uniq_cards[i].by_two + uniq_cards[i].by_three;
  }
  std::cout << all_varients;
  delete[] uniq_cards;
  delete[] uniq_values;
  delete[] cards;
  return 0;
}