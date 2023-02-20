#pragma once
#include <iostream>

template <class T>
void KthElement(T* begin, const T* kth, const T* end) {
  if (begin + 1 < end) {
    int pivot = std::rand() / ((RAND_MAX + 1u) / (end - begin));
    T pivot_value = begin[pivot];
    int first = 0;
    int last = end - begin - 1;
    while (first < last + 1) {
      while (begin[first] < pivot_value) {
        first++;
      }
      while (pivot_value < begin[last]) {
        last--;
      }
      if (last < first + 1) {
        break;
      }
      T tmpl = begin[first];
      begin[first++] = begin[last];
      begin[last--] = tmpl;
    }
    T* l = &begin[last];
    if (l < kth) {
      KthElement(l + 1, kth, end);
    } else {
      KthElement(begin, kth, l + 1);
    }
  }
}