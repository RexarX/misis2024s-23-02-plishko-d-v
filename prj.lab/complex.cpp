#include <iostream>
#include <sstream>

struct Complex {
  Complex() = default; //default constructor
  explicit Complex(const double real); //constructor initializes a complex number with a real part and sets the imaginary part to 0
  Complex(const double real, const double imaginary); //constructor initializes a complex number with a real part and an imaginary part
  bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); } //equality comparison operator that checks if two complex numbers are equal
  bool operator!=(const Complex& rhs) const { return !operator==(rhs); } //inequality comparison operator that checks if two complex numbers are not equal
  Complex& operator+=(const Complex& rhs); //addition assignment operator that adds another complex number to the current complex number
  Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); } //addition assignment operator that adds a real number to the current complex number
  Complex& operator-=(const Complex& rhs); //subtraction assignment that subtracts another complex number and the current complex number
  Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); } //subtraction assignment that subtracts a real number and the current complex number
  Complex& operator*=(const Complex& rhs); //multiplication assignment operator that multiplies another complex number to the current complex number
  Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); } //multiplication assignment operator that multiplies the current complex number by a real number
  Complex& operator/=(const Complex& rhs); //division assignment operator that multiplies another complex number to the current complex number
  Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); } //division assignment operator that multiplies the current complex number by a real number
  std::ostream& writeTo(std::ostream& ostrm) const; //function that writes the complex number to an output stream
  std::istream& readFrom(std::istream& istrm); //function that reads a complex number from an input stream

  double re{ 0.0 }; //zero-initialization
  double im{ 0.0 }; //zero-initialization

  static const char leftBrace{ '{' }; //one time initialization
  static const char separator{ ',' }; //one time initialization
  static const char rightBrace{ '}' }; //one time initialization
};

Complex operator+(const Complex& lhs, const Complex& rhs); //non-member function, addition operator that adds two complex numbers and returns the result
Complex operator-(const Complex& lhs, const Complex& rhs); //non-member function, subtraction operator that subtracts one complex number from another and returns the result 
Complex operator*(const Complex& lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.readFrom(istrm);
}

bool testParse(const std::string& str) {
  std::istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good()) {
    std::cout << "Read success: " << str << " -> " << z << '\n';
  }
  else {
    std::cout << "Read error : " << str << " -> " << z << '\n';
  }
  return istrm.good();
}

int main() {
  Complex z;
  z += Complex(8.0);
  z += 4.0;
  z = Complex(8.0) + Complex(4.0);
  z -= Complex(8.0);
  z -= 4.0;
  z = Complex(8.0) - Complex(4.0);
  z *= Complex(8.0);
  z *= 4.0;
  z = Complex(8.0) * Complex(4.0);
  /*z /= Complex(8.0);
  z /= 4.0;
  z = Complex(8.0) / Complex(4.0); */
  testParse("{8.9,9}");
  testParse("{8.9, 9}");
  testParse("{8.9,9");
  return 0;
}

Complex::Complex(const double real)
  : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
  : re(real), im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs) {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
  Complex sum(lhs);
  sum += rhs;
  return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex& Complex::operator*=(const Complex& rhs) {
  re = re * rhs.re - im * rhs.im;
  im = re * rhs.im + im * rhs.re;
  return *this;
}

/*Complex& Complex::operator*=(const double rhs) {
  re *= rhs;
  im *= rhs;
  return *this;
} */

Complex operator*(const Complex& lhs, const Complex& rhs) {
  Complex multiply;
  multiply.re = lhs.re * rhs.re - lhs.im * rhs.im;
  multiply.im = lhs.re * rhs.im + lhs.im * rhs.re;
  return multiply;
}

Complex& Complex::operator/=(const Complex& rhs) {
  re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
  im = (rhs.re * im - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
  return *this;
}

/*Complex& Complex::operator/=(const double rhs) {
  re = re / rhs;
  im = im / rhs;
  return *this;
} */

Complex operator/(const Complex& lhs, const Complex& rhs) {
  Complex division;
  division.re = (lhs.re * rhs.re + lhs.im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
  division.im = (rhs.re * lhs.im - lhs.re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
  return division;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
  ostrm << leftBrace << re << separator << im << rightBrace;
  return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
  char leftBrace(0);
  double real(0.0);
  char comma(0);
  double imaganary(0.0);
  char rightBrace(0);
  istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
  if (istrm.good()) {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) {
      re = real;
      im = imaganary;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}
