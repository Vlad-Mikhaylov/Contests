#pragma once
#include <iostream>
template <typename T>
bool BinarySearch(const T* begin, const T* end, const T& value) {
  const T* left = begin;
  const T* right = end;
  const T* middle;
  while (left < (right - 1)) {
    middle = left + (right - left) / 2;
    if (value < *middle) {
      right = middle;
    } else {
      left = middle;
    }
  }
  return !((*left < value) || (value < *left));
}
template <class T>
const T* LowerBound(const T* begin, const T* end, const T& value) {
  const T* left = begin;
  const T* right = end;
  const T* middle;
  if (!(*left < value)) {
    return left;
  }
  while (left < (right - 1)) {
    middle = left + (right - left) / 2;
    if (*middle < value) {
      left = middle;
    } else {
      right = middle;
    }
  }
  return right;
}
template <class T>
const T* UpperBound(const T* begin, const T* end, const T& value) {
  const T* left = begin;
  const T* right = end;
  const T* middle;
  if (value < *left) {
    return left;
  }
  while (left < (right - 1)) {
    middle = left + (right - left) / 2;
    if (value < *middle) {
      right = middle;
    } else {
      left = middle;
    }
  }
  return right;
}