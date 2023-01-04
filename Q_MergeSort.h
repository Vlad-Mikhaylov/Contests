#pragma once
#include <iostream>
template <typename T>
void Merge(T* first_begin, T* first_end, T* second_begin, T* second_end) {
  T* outl = new T[second_end - first_begin];
  int point_a = 0;
  int point_b = 0;
  int point_c = 0;
  T* f_b = first_begin;
  T* s_b = second_begin;
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
  for (int i = 0; i < point_b + point_a; i++) {
    *(f_b + i) = outl[i];
  }
  delete[] outl;
  return;
}

template <typename T>
void Sort(T* begin, T* end) {
  if (end - begin < 2) {
    return;
  }
  Sort(begin, begin + (end - begin) / 2);
  Sort(begin + (end - begin) / 2, end);
  Merge(begin, begin + (end - begin) / 2, begin + (end - begin) / 2, end);
}