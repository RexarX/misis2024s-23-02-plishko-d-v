#pragma once

#include <sstream>

struct Complex
{
  Complex() = default;
  Complex(const Complex& rhs) = default;
  Complex(Complex&& rhs) noexcept = default;
  Complex(const double real);
  Complex(const double real, const double imaginary);
  ~Complex() = default;

  Complex& operator=(const Complex& rhs) = default;
  Complex& operator=(Complex&& rhs) noexcept = default;

  Complex operator-() const noexcept { return Complex(-re, -im); }

  bool operator==(const Complex& rhs) noexcept;
  bool operator!=(const Complex& rhs) noexcept { return !operator==(rhs); }

  Complex& operator+=(const Complex& rhs) noexcept;
  Complex& operator+=(const double rhs) noexcept;

  Complex& operator-=(const Complex& rhs) noexcept;
  Complex& operator-=(const double rhs) noexcept;

  Complex& operator*=(const Complex& rhs) noexcept;
  Complex& operator*=(const double rhs) noexcept;

  Complex& operator/=(double rhs);
  Complex& operator/=(const Complex& rhs);

  std::ostream& writeTo(std::ostream& ostrm) const noexcept;
  std::istream& readFrom(std::istream& istrm) noexcept;

  double re{ 0.0 };
  double im{ 0.0 };

  static const char leftBrace{ '{' };
  static const char separator{ ',' };
  static const char rightBrace{ '}' };
};

bool operator==(const Complex& lhs, const Complex& rhs) noexcept;
bool operator!=(const Complex& lhs, const Complex& rhs) noexcept;

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator+(const Complex& lhs, const double rhs) noexcept;
Complex operator+(const double lhs, const Complex& rhs) noexcept;

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator-(const Complex& lhs, const double rhs) noexcept;
Complex operator-(const double lhs, const Complex& rhs) noexcept;

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator*(const Complex& lhs, const double rhs) noexcept;
Complex operator*(const double lhs, const Complex& rhs) noexcept;

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);
Complex operator/(const double lhs, const Complex& rhs);

bool TestParse(const std::string& str) noexcept;

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
  return rhs.readFrom(istrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
  return rhs.writeTo(ostrm);
}