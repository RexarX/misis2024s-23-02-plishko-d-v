#include <sstream>
#include <rational/rational.hpp>

int64_t greatest_common_divisor(const int64_t& a, const int64_t& b) noexcept {
  if (a % b == 0) { return b; }
  if (b % a == 0) { return a; }
  if (a > b) { return greatest_common_divisor(a % b, b); }

  return greatest_common_divisor(a, b % a);
}

int64_t least_common_multiple(const int64_t& a, const int64_t& b) noexcept {
  return (a * b) / greatest_common_divisor(a, b);
}

Rational::Rational(const int64_t num) noexcept
  : Rational(num, 1)
{
}

Rational::Rational(const int64_t num, const int64_t den)
  : num_(num), den_(den) {
  if (den_ == 0) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  } else if (den_ < 0) {
    num_ = -num_;
    den_ = -den_;
  }
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
  return rhs.readFrom(istrm);
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
  if (den_ != rhs.den_) {
    const int64_t temp = least_common_multiple(den_, rhs.den_);
    num_ = temp / den_ * num_ + temp / rhs.den_ * rhs.num_;
    den_ = temp;
  } else {
    num_ += rhs.num_;
  }
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
  if (den_ != rhs.den_) {
    const int64_t temp = least_common_multiple(den_, rhs.den_);
    num_ = temp / den_ * num_ - temp / rhs.den_ * rhs.num_;
    den_ = temp;
  } else {
    num_ -= rhs.num_;
  }
  return *this;
}

inline Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
  if (lhs.den() != rhs.den()) {
    const int64_t temp = least_common_multiple(lhs.den(), rhs.den());
    return  Rational(temp / lhs.den() * lhs.num() + temp / rhs.den() * rhs.num(), temp);
  } else {
    return Rational(lhs.num() + rhs.num(), lhs.den());
  }
}

inline Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
  if (lhs.den() != rhs.den()) {
    const int64_t temp = least_common_multiple(lhs.den(), rhs.den());
    return  Rational(temp / lhs.den() * lhs.num() - temp / rhs.den() * rhs.num(), temp);
  } else {
    return Rational(lhs.num() - rhs.num(), lhs.den());
  }
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  return *this;
}

inline Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs.num() * rhs.num(), lhs.den() * rhs.den());
}

Rational& Rational::operator/=(const Rational& rhs) noexcept {
  den_ *= num_;
  num_ *= rhs.den_;
  return *this;
}

inline Rational operator/(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs.num() * rhs.den(), lhs.den() * rhs.num());
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
  ostrm << num_ << separator << den_;
  return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
  int64_t num(0);
  char slash(0);
  int64_t den(1);
  istrm >> num >> slash >> den;
  if (istrm.good()) {
    if (Rational::separator == slash) {
      num_ = num;
      den_ = den;
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}