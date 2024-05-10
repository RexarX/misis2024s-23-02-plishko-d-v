#include "rational.hpp"

#include <iostream>

int64_t greatest_common_divisor(const int64_t a, const int64_t b) noexcept
{
  if (a % b == 0) { return b; }
  if (b % a == 0) { return a; }
  if (a > b) { return greatest_common_divisor(a % b, b); }

  return greatest_common_divisor(a, b % a);
}

void Rational::CheckSign() noexcept
{
  if (den_ < 0) {
    num_ = -num_;
    den_ = -den_;
  }
  return;
}

void Rational::SimplifyFraction() noexcept
{
  int64_t greatest_common_diviser = greatest_common_divisor(std::abs(num_), den_);
  if (greatest_common_diviser != 1) {
    num_ /= greatest_common_diviser;
    den_ /= greatest_common_diviser;
  }
}

int64_t least_common_multiple(const int64_t a, const int64_t b) noexcept
{
  return (a * b) / greatest_common_divisor(a, b);
}

Rational::Rational(const int64_t num)
  : Rational(num, 1)
{
}

Rational::Rational(const int64_t num, const int64_t den)
  : num_(num), den_(den)
{
  if (den_ == 0) {
    throw std::invalid_argument("Zero denumenator in Rational ctor!");
  } else if (den_ < 0) {
    num_ = -num_;
    den_ = -den_;
  }
  CheckSign();
  SimplifyFraction();
}

Rational& Rational::operator+=(const Rational& value) noexcept
{
  if (den_ != value.den_) {
    const int64_t temp = least_common_multiple(den_, value.den_);
    num_ = temp / den_ * num_ + temp / value.den_ * value.num_;
    den_ = temp;
  }
  else { num_ += value.num_; }
  SimplifyFraction();
  return *this;
}

Rational& Rational::operator*=(const Rational& value) noexcept
{
  num_ *= value.num_;
  den_ *= value.den_;
  SimplifyFraction();
  return *this;
}

Rational& Rational::operator/=(const Rational& value)
{
  if (value.num_ == 0) {
    throw std::invalid_argument("Division by zero is not allowed!");
  }
  num_ *= value.den_;
  den_ *= value.num_;
  CheckSign();
  SimplifyFraction();
  return *this;
}

inline Rational operator+(const Rational& lhs, const Rational& rhs) noexcept
{
  Rational result = lhs;
  result += rhs;
  return result;
}

inline Rational operator*(const Rational& lhs, const Rational& rhs) noexcept
{
  Rational result = lhs;
  result *= rhs;
  return result;
}

inline Rational operator/(const Rational& lhs, const Rational& rhs)
{
  Rational result = lhs;
  result /= rhs;
  return result;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const noexcept
{
  ostrm << num_ << '/' << den_;
  return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) noexcept
{
  int64_t num(0);
  char delimiter(0);
  int64_t den(1);
  istrm >> num;
  istrm.get(delimiter);
  const int64_t trash = istrm.peek();
  istrm >> den;
  if (!istrm || trash > '9' || trash < '0') {
    istrm.setstate(std::ios_base::failbit);
    return istrm;
  }
  if (istrm.good() || istrm.eof()) {
    if ('/' == delimiter && den > 0) {
      num_ = num;
      den_ = den;
    }
    else { istrm.setstate(std::ios_base::failbit); }
  }
  return istrm;
}