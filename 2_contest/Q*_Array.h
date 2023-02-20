#ifndef Array_h
#define Array_h
#define ARRAY_TRAITS_IMPLEMENTED
#include <cinttypes>
#include <stdexcept>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};

template <class T, size_t N>
class Array {
 public:
  T arr_[N];
  T& operator[](int i);
  const T& operator[](int i) const;
  T& At(size_t idx);
  const T& At(size_t idx) const;
  T& Front();
  T Front() const;
  T& Back();
  T Back() const;
  const T* Data() const;
  size_t Size() const;
  bool Empty() const;
  void Fill(const T& value);
  void Swap(Array<T, N>& other);
};

template <class T, size_t N>
T& Array<T, N>::operator[](int i) {
  return *(arr_ + i);
}

template <class T, size_t N>
const T& Array<T, N>::operator[](int i) const {
  return *(arr_ + i);
}

template <class T, size_t N>
const T& Array<T, N>::At(size_t idx) const {
  if (idx < N) {
    return arr_[idx];
  }
  throw ArrayOutOfRange{};
}

template <class T, size_t N>
T& Array<T, N>::At(size_t idx) {
  if (idx < N) {
    return arr_[idx];
  }
  throw ArrayOutOfRange{};
}

template <class T, size_t N>
T Array<T, N>::Front() const {
  return arr_[0];
}

template <class T, size_t N>
T& Array<T, N>::Front() {
  return arr_[0];
}

template <class T, size_t N>
T Array<T, N>::Back() const {
  return arr_[N - 1];
}

template <class T, size_t N>
T& Array<T, N>::Back() {
  return arr_[N - 1];
}

template <class T, size_t N>
const T* Array<T, N>::Data() const {
  return arr_;
}

template <class T, size_t N>
size_t Array<T, N>::Size() const {
  return N;
}

template <class T, size_t N>
bool Array<T, N>::Empty() const {
  return N == 0;
}

template <class T, size_t N>
void Array<T, N>::Fill(const T& value) {
  for (size_t i = 0; i < N; ++i) {
    arr_[i] = value;
  }
}

template <class T, size_t N>
void Array<T, N>::Swap(Array<T, N>& other) {
  if (N > 0) {
    for (size_t i = 0; i < N; ++i) {
      T tmp = arr_[i];
      arr_[i] = other.arr_[i];
      other.arr_[i] = tmp;
    }
  }
}

template <class T>
int GetSize(T value) {
  return 0 + (sizeof(value) - sizeof(value));
}

template <class T, size_t N>
int GetSize(T (&array)[N]) {
  return N + (array - array);
}
template <class T>
int GetRank(T value) {
  return 0 + (sizeof(value) - sizeof(value));
}
template <class T, size_t N>
int GetRank(T (&array)[N]) {
  return GetRank(array[0]) + 1;
}
template <class T>
int GetNumElements(T value) {
  return 1 + (sizeof(value) - sizeof(value));
}
template <class T, size_t N>
int GetNumElements(T (&array)[N]) {
  return GetNumElements(array[0]) * N;
}
#endif
