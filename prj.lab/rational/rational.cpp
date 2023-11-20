#include <iostream>
#include <sstream>
#include <rational/rational.hpp>

Rational::Rational(const long long int num, const unsigned int den)
  : num_(num), den_(den)
{
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
  return rhs.readFrom(istrm);
}

Rational& Rational::operator+=(const Rational& rhs) {
}

Rational& Rational::operator-=(const Rational& rhs) {
}

inline Rational operator+(const Rational& lhs, const Rational& rhs) {
}

inline Rational operator-(const Rational& lhs, const Rational& rhs) {
}

Rational& Rational::operator*=(const Rational& rhs) {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  return *this;
}

inline Rational operator*(const Rational& lhs, const Rational& rhs) {
}

Rational& Rational::operator/=(const Rational& rhs) {
}

inline Rational operator/(const Rational& lhs, const Rational& rhs) {
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
  ostrm << leftBrace << num_ << separator << den_ << rightBrace;
  return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
  char leftBrace(0);
  double num(0);
  char slash(0);
  double den(1);
  char rightBrace(0);
  istrm >> leftBrace >> num >> slash >> den >> rightBrace;
  if (istrm.good()) {
    if ((Rational::leftBrace == leftBrace) && (Rational::separator == slash) && (Rational::rightBrace == rightBrace)) {
      num_ = num;
      den_ = den;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}