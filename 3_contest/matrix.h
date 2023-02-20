#ifndef MATRIX_H
#define MATRIX_H
#include <stdexcept>
#include <iostream>

class MatrixIsDegenerateError : public std::runtime_error {
 public:
  MatrixIsDegenerateError() : std::runtime_error("MatrixIsDegenerateError") {
  }
};

class MatrixOutOfRange : public std::out_of_range {
 public:
  MatrixOutOfRange() : std::out_of_range("MatrixOutOfRange") {
  }
};

template <class T, size_t N, size_t M>
class Matrix {
 public:
  T under_matrix[N][M];
  size_t RowsNumber() const;
  size_t ColumnsNumber() const;
  T& operator()(size_t, size_t);
  const T& operator()(size_t, size_t) const;
  T& At(size_t, size_t);
  const T& At(size_t, size_t) const;
  Matrix<T, N, M>& operator*=(int64_t);
  Matrix<T, N, M>& operator/=(int64_t);
};

template <class T, size_t N, size_t M>
size_t Matrix<T, N, M>::ColumnsNumber() const {
  return M;
}
template <class T, size_t N, size_t M>
size_t Matrix<T, N, M>::RowsNumber() const {
  return N;
}

template <class T, size_t N, size_t M>
T& Matrix<T, N, M>::operator()(size_t i, size_t j) {
  return this->under_matrix[i][j];
}
template <class T, size_t N, size_t M>
const T& Matrix<T, N, M>::operator()(size_t i, size_t j) const {
  return this->under_matrix[i][j];
}
template <class T, size_t N, size_t M>
T& Matrix<T, N, M>::At(size_t i, size_t j) {
  if (i >= N || j >= M) {
    throw MatrixOutOfRange();
  }
  return this->under_matrix[i][j];
}
template <class T, size_t N, size_t M>
const T& Matrix<T, N, M>::At(size_t i, size_t j) const {
  if (i >= N || j >= M) {
    throw MatrixOutOfRange();
  }
  return this->under_matrix[i][j];
}

template <class T, size_t N, size_t M>
Matrix<T, M, N> GetTransposed(const Matrix<T, N, M>& matrix_to_convert) {
  Matrix<T, M, N> transposed;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      transposed(j, i) = matrix_to_convert(i, j);
    }
  }
  return transposed;
}
template <class T, size_t N, size_t M, size_t K, size_t L>
bool operator==(const Matrix<T, N, M>& matrix_to_convert_1, const Matrix<T, K, L>& matrix_to_convert_2) {
  if (N != K || M != L) {
    throw MatrixOutOfRange();
  }
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      if (matrix_to_convert_1(i, j) != matrix_to_convert_2(i, j)) {
        return false;
      }
    }
  }
  return true;
}
template <class T, size_t N, size_t M, size_t K, size_t L>
bool operator!=(const Matrix<T, N, M>& matrix_to_convert_1, const Matrix<T, K, L>& matrix_to_convert_2) {
  return !(matrix_to_convert_1 == matrix_to_convert_2);
}

template <class T, size_t N, size_t M, size_t K, size_t L>
Matrix<T, N, M> operator+(const Matrix<T, N, M>& matrix_to_convert_1, const Matrix<T, K, L>& matrix_to_convert_2) {
  if (N != K || M != L) {
    throw MatrixOutOfRange();
  }
  Matrix<T, N, M> result_matrix;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      result_matrix(i, j) = matrix_to_convert_1(i, j) + matrix_to_convert_2(i, j);
    }
  }
  return result_matrix;
}

template <class T, size_t N, size_t M, size_t K, size_t L>
Matrix<T, N, M> operator-(const Matrix<T, N, M>& matrix_to_convert_1, const Matrix<T, K, L>& matrix_to_convert_2) {
  if (N != K || M != L) {
    throw MatrixOutOfRange();
  }
  Matrix<T, N, M> result_matrix;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      result_matrix(i, j) = matrix_to_convert_1(i, j) - matrix_to_convert_2(i, j);
    }
  }
  return result_matrix;
}

template <class T, size_t N, size_t M, size_t K, size_t L>
Matrix<T, N, L> operator*(const Matrix<T, N, M>& matrix_to_convert, const Matrix<T, K, L>& matrix_to_convert_2) {
  if (M != K) {
    throw MatrixOutOfRange();
  }
  Matrix<T, N, L> result_matrix;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < L; j++) {
      result_matrix(i, j) = 0;
    }
  }
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < L; j++) {
      for (size_t k = 0; k < M; ++k) {
        result_matrix(i, j) += (matrix_to_convert(i, k) * matrix_to_convert_2(k, j));
      }
    }
  }
  return result_matrix;
}

template <class T, size_t N, size_t M, size_t K, size_t L>
Matrix<T, N, M>& operator+=(Matrix<T, N, M>& matrix_to_convert_1, const Matrix<T, K, L>& matrix_to_convert_2) {
  if (N != K || M != L) {
    throw MatrixOutOfRange();
  }
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      matrix_to_convert_1(i, j) += matrix_to_convert_2(i, j);
    }
  }
  return matrix_to_convert_1;
}

template <class T, size_t N, size_t M, size_t K, size_t L>
Matrix<T, N, M>& operator-=(Matrix<T, N, M>& matrix_to_convert_1, const Matrix<T, K, L>& matrix_to_convert_2) {
  if (N != K || M != L) {
    throw MatrixOutOfRange();
  }
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      matrix_to_convert_1(i, j) -= matrix_to_convert_2(i, j);
    }
  }
  return matrix_to_convert_1;
}

template <class T, size_t N, size_t M, size_t L, size_t K>
Matrix<T, N, M>& operator*=(Matrix<T, N, M>& matrix_to_convert_1, const Matrix<T, K, L>& matrix_to_convert_2) {
  if (M != L) {
    throw MatrixOutOfRange();
  }
  matrix_to_convert_1 = matrix_to_convert_1 * matrix_to_convert_2;
  return matrix_to_convert_1;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator*=(int64_t num) {
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      this->under_matrix[i][j] *= num;
    }
  }
  return *this;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator/=(int64_t num) {
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      this->under_matrix[i][j] /= num;
    }
  }
  return *this;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator*(int64_t num, const Matrix<T, N, M>& matrix_to_convert) {
  auto result_matrix = matrix_to_convert;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      result_matrix(i, j) = matrix_to_convert(i, j) * num;
    }
  }
  return result_matrix;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator*(const Matrix<T, N, M>& matrix_to_convert, int64_t num) {
  return num * matrix_to_convert;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator/(const Matrix<T, N, M>& matrix_to_convert, int64_t num) {
  auto result_matrix = matrix_to_convert;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      result_matrix(i, j) = matrix_to_convert(i, j) / num;
    }
  }
  return result_matrix;
}

template <class T, size_t N, size_t M>
std::istream& operator>>(std::istream& is, Matrix<T, N, M>& matrix_to_convert) {
  T num = 0;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      is >> num;
      matrix_to_convert.under_matrix[i][j] = num;
    }
  }
  return is;
}
template <class T, size_t N, size_t M>
std::ostream& operator<<(std::ostream& os, Matrix<T, N, M>& matrix_to_convert) {
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M - 1; j++) {
      os << matrix_to_convert(i, j);
      if (j != M - 1) {
        os << ' ';
      }
    }
    os << matrix_to_convert(i, M - 1) << '\n';
  }
  return os;
}
#endif