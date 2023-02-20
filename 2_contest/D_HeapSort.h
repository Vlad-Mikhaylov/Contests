#pragma once
#include <algorithm>

template <class T>
void Heapify(T* begin, T* end, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;
  if (left < end - begin && begin[largest] < begin[left]) {
    largest = left;
  }
  if (right < end - begin && begin[largest] < begin[right]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(begin[i], begin[largest]);
    Heapify(begin, end, largest);
  }
}

template <class T>
void MakeHeap(T* begin, T* end) {
  for (int i = (end - begin) / 2 - 1; i >= 0; i--) {
    Heapify(begin, end, i);
  }
}

template <class T>
void SortHeap(T* begin, T* end) {
  MakeHeap(begin, end);
  for (int i = end - begin - 1; i >= 0; i--) {
    std::swap(begin[0], begin[i]);
    Heapify(begin, begin + i, 0);
  }
}