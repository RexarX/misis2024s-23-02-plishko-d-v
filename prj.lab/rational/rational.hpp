#ifndef RATIONAL_HPP
#define RATIONAL_HPP

class Rational {
public:
  Rational() = default;
  Rational(const long long int num, const long long int den);
  bool operator==(const Rational& lhs) const { return (num_ == lhs.num_) && (den_ == lhs.den_); }
  bool operator!=(const Rational& lhs) const { return !operator==(lhs); }
  Rational(const long long int num);
  Rational(const long long int num, const unsigned int den);
  Rational& operator+=(const Rational& lhs);
  Rational& operator+=(const long long int lhs) { return operator+=(Rational(lhs)); }
  Rational& operator-=(const Rational& lhs);
  Rational& operator-=(const long long int lhs) { return operator-=(Rational(lhs)); }
  Rational& operator*=(const Rational& lhs);
  Rational& operator*=(const long long int lhs) { return operator*=(Rational(lhs)); }
  Rational& operator/=(const Rational& lhs);
  Rational& operator/=(const long long int lhs) { return operator/=(Rational(lhs)); }

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);

  long long int num_{ 0 };
  unsigned int den_{ 1 };

private:
  long long int num_{ 0 };
  unsigned int den_{ 1 };

  static const char leftBrace{ '{' };
  static const char separator{ '/' };
  static const char rightBrace{ '}' };
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

#endif