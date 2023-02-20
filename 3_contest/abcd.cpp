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

template <class T, size_t Rows, size_t Columns>
class Matrix {
 public:
  T matrix[Rows][Columns];
  size_t RowsNumber() const;
  size_t ColumnsNumber() const;
  T& operator()(size_t, size_t);
  const T& operator()(size_t, size_t) const;
  T& At(size_t, size_t);
  const T& At(size_t, size_t) const;
};

template <class T, size_t Rows, size_t Columns>
size_t Matrix<T, Rows, Columns>::RowsNumber() const {
  return Rows;
}

template <class T, size_t Rows, size_t Columns>
size_t Matrix<T, Rows, Columns>::ColumnsNumber() const {
  return Columns;
}

template <class T, size_t FirstRows, size_t FirstColumns, size_t SecondRows, size_t SecondColumns>
bool operator==(const Matrix<T, FirstRows, FirstColumns>& first, const Matrix<T, SecondRows, SecondColumns>& second) {
  if (FirstRows != SecondRows || FirstColumns != SecondColumns) {
    throw MatrixOutOfRange{};
  }
  for (size_t i = 0; i < FirstRows; ++i) {
    for (size_t j = 0; j < FirstColumns; ++j) {
      if (first.matrix[i][j] != second.matrix[i][j]) {
        return false;
      }
    }
  }
  return true;
}

template <class T, size_t FirstRows, size_t FirstColumns, size_t SecondRows, size_t SecondColumns>
bool operator!=(const Matrix<T, FirstRows, FirstColumns>& first, const Matrix<T, SecondRows, SecondColumns>& second) {
  return !(first == second);
}

template <class T, size_t Rows, size_t Columns>
T& Matrix<T, Rows, Columns>::operator()(size_t first, size_t second) {
  return this->matrix[first][second];
}

template <class T, size_t Rows, size_t Columns>
const T& Matrix<T, Rows, Columns>::operator()(size_t first, size_t second) const {
  return this->matrix[first][second];
}

template <class T, size_t Rows, size_t Columns>
T& Matrix<T, Rows, Columns>::At(size_t first, size_t second) {
  if (first >= Rows || second >= Columns) {
    throw MatrixOutOfRange{};
  }
  return this->matrix[first][second];
}

template <class T, size_t Rows, size_t Columns>
const T& Matrix<T, Rows, Columns>::At(size_t first, size_t second) const {
  if (first >= Rows || second >= Columns) {
    throw MatrixOutOfRange{};
  }
  return this->matrix[first][second];
}

template <class T, size_t FirstRows, size_t FirstColumns, size_t SecondRows, size_t SecondColumns>
Matrix<T, FirstRows, FirstColumns> operator+(const Matrix<T, FirstRows, FirstColumns>& first,
                                             const Matrix<T, SecondRows, SecondColumns>& second) {
  if (FirstRows != SecondRows || FirstColumns != SecondColumns) {
    throw MatrixOutOfRange{};
  }
  Matrix<T, FirstRows, FirstColumns> result;
  for (size_t i = 0; i < FirstRows; ++i) {
    for (size_t j = 0; j < FirstColumns; ++j) {
      result.matrix[i][j] = first.matrix[i][j] + second.matrix[i][j];
    }
  }
  return result;
}

template <class T, size_t FirstRows, size_t FirstColumns, size_t SecondRows, size_t SecondColumns>
Matrix<T, FirstRows, FirstColumns>& operator+=(Matrix<T, FirstRows, FirstColumns>& first,
                                               const Matrix<T, SecondRows, SecondColumns>& second) {
  if (FirstRows != SecondRows || FirstColumns != SecondColumns) {
    throw MatrixOutOfRange{};
  }
  for (size_t i = 0; i < FirstRows; ++i) {
    for (size_t j = 0; j < FirstColumns; ++j) {
      first.matrix[i][j] += second.matrix[i][j];
    }
  }
  return first;
}

template <class T, size_t FirstRows, size_t FirstColumns, size_t SecondRows, size_t SecondColumns>
Matrix<T, FirstRows, FirstColumns> operator-(const Matrix<T, FirstRows, FirstColumns>& first,
                                             const Matrix<T, SecondRows, SecondColumns>& second) {
  return first + (-1) * second;
}
template <class T, size_t FirstRows, size_t FirstColumns, size_t SecondRows, size_t SecondColumns>
Matrix<T, FirstRows, FirstColumns>& operator-=(Matrix<T, FirstRows, FirstColumns>& first,
                                               const Matrix<T, SecondRows, SecondColumns>& second) {
  return first += (-1) * second;
}

template <class T, size_t FirstRows, size_t FirstColumns, size_t SecondRows, size_t SecondColumns>
Matrix<T, FirstRows, SecondColumns> operator*(const Matrix<T, FirstRows, FirstColumns>& first,
                                              const Matrix<T, SecondRows, SecondColumns>& second) {
  if (FirstColumns != SecondRows) {
    throw MatrixOutOfRange{};
  }
  Matrix<T, FirstRows, SecondColumns> result{};
  for (size_t i = 0; i < FirstRows; ++i) {
    for (size_t j = 0; j < SecondColumns; ++j) {
      for (size_t k = 0; k < FirstColumns; ++k) {
        result.matrix[i][j] += first.matrix[i][k] * second.matrix[k][j];
      }
    }
  }
  return result;
}

template <class T, size_t FirstRows, size_t FirstColumns, size_t SecondRows, size_t SecondColumns>
Matrix<T, FirstRows, FirstColumns>& operator*=(Matrix<T, FirstRows, FirstColumns>& first,
                                               const Matrix<T, SecondRows, SecondColumns>& second) {
  if (FirstColumns != SecondColumns) {
    throw MatrixOutOfRange{};
  }
  first = first * second;
  return first;
}

template <class T, size_t Rows, size_t Columns>
Matrix<T, Columns, Rows> GetTransposed(const Matrix<T, Rows, Columns>& matr) {
  Matrix<T, Columns, Rows> result;
  for (size_t i = 0; i < Columns; ++i) {
    for (size_t j = 0; j < Rows; ++j) {
      result.matrix[i][j] = matr.matrix[j][i];
    }
  }
  return result;
}

template <class T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> operator*(int64_t value, const Matrix<T, Rows, Columns>& matr) {
  auto result = matr;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      result.matrix[i][j] = matr.matrix[i][j] * value;
    }
  }
  return result;
}

template <class T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> operator*(const Matrix<T, Rows, Columns>& matr, int64_t value) {
  return value * matr;
}

template <class T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns>& operator*=(Matrix<T, Rows, Columns>& matr, int64_t value) {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      matr.matrix[i][j] *= value;
    }
  }
  return matr;
}

template <class T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> operator/(int64_t value, const Matrix<T, Rows, Columns>& matr) {
  auto result = matr;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      result.matrix[i][j] = matr.matr  Matrix<T, N, L> result_matrix;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < L; j++) {
      result_matrix(i, j) = 0;
    }
  }
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < L; j++) {
      for (size_t k = 0; k < M; ++k) {
        result_matrix(i, j) += (matrix_to_convert_1(i, k) * matrix_to_convert_2(k, j));
      }
    }
  }
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < L; j++) {
      matrix_to_convert_1(i, j) = result_matrix(i, j);
    }
  }ix[i][j] / value;
    }
  }
  return result;
}

template <class T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> operator/(const Matrix<T, Rows, Columns>& matr, int64_t value) {
  return value / matr;
}

template <class T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns>& operator/=(Matrix<T, Rows, Columns>& matr, int64_t value) {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      matr.matrix[i][j] /= value;
    }
  }
  return matr;
}

template <class T, size_t Rows, size_t Columns>
std::istream& operator>>(std::istream& is, Matrix<T, Rows, Columns>& matr) {
  T value;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      is >> value;
      matr.matrix[i][j] = value;
    }
  }
  return is;
}

template <class T, size_t Rows, size_t Columns>
std::ostream& operator<<(std::ostream& os, const Matrix<T, Rows, Columns>& matr) {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns - 1; ++j) {
      os << matr.matrix[i][j] << ' ';
    }
    os << matr.matrix[i][Columns - 1] << '\n';
  }
  return os;
}
#endif