#include "complex.hpp"

#include <stdexcept>

static const double epsilon = 2 * std::numeric_limits<double>::epsilon();

Complex::Complex(const double real)
  : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
  : re(real), im(imaginary)
{
}

bool Complex::operator==(const Complex& rhs) noexcept
{
  return (std::abs(re - rhs.re) < epsilon && std::abs(im - rhs.im) < epsilon);
}

Complex& Complex::operator+=(const Complex& rhs) noexcept
{
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex& Complex::operator+=(const double rhs) noexcept
{
  re += rhs;
  return *this;
}

bool operator==(const Complex& lhs, const Complex& rhs) noexcept
{
  return (std::abs(lhs.re - rhs.re) < epsilon && std::abs(lhs.im - rhs.im) < epsilon);
}

bool operator!=(const Complex& lhs, const Complex& rhs) noexcept
{
  return !operator==(lhs, rhs);
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept
{
  return Complex(lhs) += Complex(rhs);
}

Complex operator+(const Complex& lhs, const double rhs) noexcept
{
  return Complex(lhs) += Complex(rhs);
}

Complex operator+(const double lhs, const Complex& rhs) noexcept
{
  return Complex(lhs) += Complex(rhs);
}

Complex& Complex::operator-=(const Complex& rhs) noexcept
{
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

Complex& Complex::operator-=(const double rhs) noexcept
{
  re -= rhs;
  return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept
{
  return Complex(lhs) -= Complex(rhs);
}

Complex operator-(const Complex& lhs, const double rhs) noexcept
{
  return Complex(lhs) -= Complex(rhs);
}

Complex operator-(const double lhs, const Complex& rhs) noexcept
{
  return Complex(lhs) -= Complex(rhs);
}

Complex& Complex::operator*=(const Complex& rhs) noexcept
{
  double real = re * rhs.re - im * rhs.im;
  im = im * rhs.re + re * rhs.im;
  re = real;
  return *this;
}

Complex& Complex::operator*=(const double rhs) noexcept
{
  re *= rhs;
  im *= rhs;
  return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept
{
  return Complex(lhs) *= Complex(rhs);
}

Complex operator*(const Complex& lhs, const double rhs) noexcept
{
  return Complex(lhs) *= Complex(rhs);
}

Complex operator*(const double lhs, const Complex& rhs) noexcept
{
  return Complex(lhs) *= Complex(rhs);
}

Complex& Complex::operator/=(double rhs) {
  if (std::abs(rhs) < epsilon) {
    throw std::invalid_argument("Division by zero is not allowed!");
  }
  re /= rhs;
  im /= rhs;
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  if (std::abs(rhs.re) < epsilon && std::abs(rhs.im) < epsilon) {
    throw std::invalid_argument("Division by zero is not allowed!");
  }
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  if (std::abs(denominator) > epsilon) {
    *this *= Complex(rhs.re, -rhs.im);
    *this /= denominator;
    return *this;
  } else {
    throw std::invalid_argument("Non-zero denominator is required!");
  }
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) /= Complex(rhs);
}

Complex operator/(const Complex& lhs, const double rhs) {
  return Complex(lhs) /= Complex(rhs);
}

Complex operator/(const double lhs, const Complex& rhs) {
  return Complex(lhs) /= Complex(rhs);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const noexcept {
  ostrm << Complex::leftBrace << re << Complex::separator << im << Complex::rightBrace;
  return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) noexcept {
  char left_brase = 0;
  double real = 0.0;
  char comma = 0;
  double imaginary = 0.0;
  char right_brase = 0;
  istrm >> left_brase >> real >> comma >> imaginary >> right_brase;
  if (istrm.good()) {
    if (left_brase == Complex::leftBrace && comma == Complex::separator &&
        right_brase == Complex::rightBrace) {
      re = real;
      im = imaginary;
    }
    else { istrm.setstate(std::ios_base::failbit); }
  }
  return istrm;
}