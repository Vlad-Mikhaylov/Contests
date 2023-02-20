#ifndef Rational_h
#define Rational_h
#include <stdexcept>
#include <iostream>
#include <cinttypes>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Rational {
  int32_t m_;
  int32_t n_;

 public:
  void MakeNormal();
  Rational();
  Rational(int32_t num);  // NOLINT
  Rational(int32_t m, int32_t n);
  Rational(const Rational& other);
  Rational& operator=(const Rational& other);
  int32_t GetNumerator() const;
  int32_t GetDenominator() const;
  void SetNumerator(int32_t m);
  void SetDenominator(int32_t n);
};

Rational operator+(const Rational& first, const Rational& right);
Rational operator-(const Rational& first, const Rational& right);
Rational operator*(const Rational& first, const Rational& right);
Rational operator/(const Rational& first, const Rational& right);
Rational& operator+=(Rational& first, const Rational& right);
Rational& operator-=(Rational& first, const Rational& right);
Rational& operator*=(Rational& first, const Rational& right);
Rational& operator/=(Rational& first, const Rational& right);
Rational operator-(const Rational& value);
Rational operator+(const Rational& value);

Rational& operator++(Rational& value);
Rational& operator--(Rational& value);
Rational operator++(Rational& value, int);
Rational operator--(Rational& value, int);

bool operator>(const Rational& first, const Rational& right);
bool operator>=(const Rational& first, const Rational& right);
bool operator<(const Rational& first, const Rational& right);
bool operator<=(const Rational& first, const Rational& right);
bool operator==(const Rational& first, const Rational& right);
bool operator!=(const Rational& first, const Rational& right);

std::ostream& operator<<(std::ostream& os, const Rational& value);
std::istream& operator>>(std::istream& is, Rational& value);
#endif