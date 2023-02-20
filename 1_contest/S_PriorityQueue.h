#pragma once
#include <iostream>
template <typename T>
void Swap(T& arg_1, T& arg_2) {
  T tmp = arg_1;
  arg_1 = arg_2;
  arg_2 = tmp;
}
template <class T>
void PushHeap(T* begin, T* end) {
  auto i = (end - begin) / 2 - 1;
  auto object = end - begin - 1;
  while (i >= 0) {
    if (begin[i] < begin[object]) {
      Swap(begin[i], begin[object]);
      object = i;
      if (i % 2 == 0) {
        i = i / 2 - 1;
      } else {
        i = i / 2;
      }
    } else {
      return;
    }
  }
}
template <class T>
void PopHeap(T* begin, T* end) {
  Swap(begin[0], *(end - 1));
  auto object = 0;
  auto l = end - begin - 2;
  while (2 * object + 1 <= l) {
    if (2 * object + 2 == l + 1) {
      if (begin[object] < begin[2 * object + 1]) {
        Swap(begin[object], begin[2 * object + 1]);
        return;
      } else {
        return;
      }
    } else {
      if (begin[object] < begin[2 * object + 1] or begin[object] < begin[2 * object + 2]) {
        if (begin[2 * object + 1] < begin[2 * object + 2]) {
          Swap(begin[object], begin[2 * object + 2]);
          object = 2 * object + 2;
        } else {
          Swap(begin[object], begin[2 * object + 1]);
          object = 2 * object + 1;
        }
      } else {
        return;
      }
    }
  }
}