#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <sstream>

struct Complex {
  Complex() = default;
  Complex(const Complex&) = default;
  explicit Complex(const double real);
  Complex(const double real, const double imaginary);
  Complex& operator=(const Complex&) = default;
  ~Complex() = default;

  bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
  bool operator!=(const Complex& rhs) const { return !operator==(rhs); }

  Complex& operator+=(const Complex& rhs);
  Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
  Complex& operator-=(const Complex& rhs);
  Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
  Complex& operator*=(const Complex& rhs);
  Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); }
  Complex& operator/=(const Complex& rhs);
  Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);
 
  double re{ 0.0 };
  double im{ 0.0 };

  static const char leftBrace{ '{' };
  static const char separator{ ',' };
  static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs); 
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

Complex operator+(const Complex& lhs, const double& rhs) { return operator+(lhs, Complex(rhs)); }
Complex operator-(const Complex& lhs, const double& rhs) { return operator-(lhs, Complex(rhs)); }
Complex operator*(const Complex& lhs, const double& rhs) { return operator*(lhs, Complex(rhs)); }
Complex operator/(const Complex& lhs, const double& rhs) { return operator/(lhs, Complex(rhs)); }

Complex operator+(const double& lhs, const Complex& rhs) { return operator+(Complex(lhs), rhs); }
Complex operator-(const double& lhs, const Complex& rhs) { return operator-(Complex(lhs), rhs); }
Complex operator*(const double& lhs, const Complex& rhs) { return operator*(Complex(lhs), rhs); }
Complex operator/(const double& lhs, const Complex& rhs) { return operator/(Complex(lhs), rhs); }

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
  return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
  return rhs.ReadFrom(istrm);
}

#endif
