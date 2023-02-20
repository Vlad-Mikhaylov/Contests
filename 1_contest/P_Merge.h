#pragma once
#include <iostream>
template <typename T, typename U, typename W>
W* Merge(const T* first_begin, const T* first_end, const U* second_begin, const U* second_end, W* out) {
  int point_a = 0;
  int point_b = 0;
  int point_c = 0;
  const T* f_b = first_begin;
  const U* s_b = second_begin;
  W* outl = out;
  while ((point_a < first_end - first_begin) && (point_b < second_end - second_begin)) {
    if ((f_b[point_a] < s_b[point_b]) || !((f_b[point_a] < s_b[point_b]) || (s_b[point_b] < f_b[point_a]))) {
      outl[point_c] = f_b[point_a];
      point_a++;
      point_c++;
    } else {
      outl[point_c] = s_b[point_b];
      point_b++;
      point_c++;
    }
  }
  while (point_a < first_end - first_begin) {
    outl[point_c] = f_b[point_a];
    point_a++;
    point_c++;
  }
  while (point_b < second_end - second_begin) {
    outl[point_c] = s_b[point_b];
    point_b++;
    point_c++;
  }
  return outl;
}