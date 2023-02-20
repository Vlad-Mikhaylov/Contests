#include "rational.h"
#include <stdexcept>
#include <iostream>
#include <cinttypes>
#include <numeric>

void Rational::MakeNormal() {
  if (n_ == 0) {
    throw RationalDivisionByZero{};
  }
  int32_t gcd = std::gcd(std::abs(m_), std::abs(n_));
  m_ /= gcd;
  n_ /= gcd;
  if (n_ < 0) {
    n_ *= -1;
    m_ *= -1;
  }
}

Rational& Rational::operator=(const Rational& other) = default;

int32_t Rational::GetNumerator() const {
  return m_;
}
int32_t Rational::GetDenominator() const {
  return n_;
}
void Rational::SetNumerator(int32_t m) {
  m_ = m;
  MakeNormal();
}
void Rational::SetDenominator(int32_t n) {
  n_ = n;
  MakeNormal();
}
Rational::Rational() : m_(0), n_(1) {
}
Rational::Rational(int32_t num) : m_(num), n_(1) {
}
Rational::Rational(int32_t m, int32_t n) : m_(m), n_(n) {
  MakeNormal();
}
Rational::Rational(const Rational& other) {
  m_ = other.m_;
  n_ = other.n_;
}
Rational operator+(const Rational& first, const Rational& right) {
  int32_t num1 = first.GetNumerator();
  int32_t den1 = first.GetDenominator();
  int32_t num2 = right.GetNumerator();
  int32_t den2 = right.GetDenominator();
  int32_t ret_num = num1 * den2 + den1 * num2;
  int32_t ret_den = den1 * den2;
  return Rational(ret_num, ret_den);
}
Rational operator-(const Rational& first, const Rational& right) {
  int32_t num1 = first.GetNumerator();
  int32_t den1 = first.GetDenominator();
  int32_t num2 = right.GetNumerator();
  int32_t den2 = right.GetDenominator();
  int32_t ret_num = num1 * den2 - den1 * num2;
  int32_t ret_den = den1 * den2;
  return Rational(ret_num, ret_den);
}
Rational& operator-=(Rational& first, const Rational& right) {
  first = first - right;
  return first;
}
Rational& operator*=(Rational& first, const Rational& right) {
  first = first * right;
  return first;
}
Rational operator*(const Rational& first, const Rational& right) {
  return Rational(first.GetNumerator() * right.GetNumerator(), first.GetDenominator() * right.GetDenominator());
}
Rational operator/(const Rational& first, const Rational& right) {
  return Rational(first.GetNumerator() * right.GetDenominator(), first.GetDenominator() * right.GetNumerator());
}

Rational& operator+=(Rational& first, const Rational& right) {
  first = first + right;
  return first;
}
Rational& operator/=(Rational& first, const Rational& right) {
  first = first / right;
  return first;
}

Rational operator-(const Rational& value) {
  return Rational(-value.GetNumerator(), value.GetDenominator());
}
Rational operator+(const Rational& value) {
  return Rational(value.GetNumerator(), value.GetDenominator());
}
Rational& operator++(Rational& value) {
  value += Rational(1);
  return value;
}
Rational& operator--(Rational& value) {
  value -= Rational(1);
  return value;
}
Rational operator++(Rational& value, int) {
  Rational tmp;
  tmp = value;
  value += Rational(1);
  return tmp;
}
Rational operator--(Rational& value, int) {
  Rational tmp;
  tmp = value;
  value -= Rational(1);
  return tmp;
}
bool operator>(const Rational& first, const Rational& right) {
  return (first.GetNumerator() * right.GetDenominator() > first.GetDenominator() * right.GetNumerator());
}
bool operator<(const Rational& first, const Rational& right) {
  return (first.GetNumerator() * right.GetDenominator() < first.GetDenominator() * right.GetNumerator());
}
bool operator>=(const Rational& first, const Rational& right) {
  return !(first < right);
}
bool operator<=(const Rational& first, const Rational& right) {
  return !(first > right);
}
bool operator==(const Rational& first, const Rational& right) {
  return first.GetNumerator() == right.GetNumerator() and first.GetDenominator() == right.GetDenominator();
}
bool operator!=(const Rational& first, const Rational& right) {
  return !(first == right);
}

std::ostream& operator<<(std::ostream& os, const Rational& value) {
  os << value.GetNumerator();
  if (value.GetDenominator() != 1) {
    os << "/" << value.GetDenominator();
  }
  return os;
}
std::istream& operator>>(std::istream& is, Rational& value) {
  int32_t n;
  int32_t d;
  char dev;
  is >> n;
  if (is.peek() == '/') {
    is >> dev;
    is >> d;
    value = Rational(n, d);
  } else {
    value = Rational(n);
  }
  return is;
}