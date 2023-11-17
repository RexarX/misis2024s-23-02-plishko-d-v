#ifndef COMPLEX_HPP
#define COMPLEX_HPP

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
Complex operator*(const Complex& lhs, const Complex& rhs); //non-member function, multiplication operator that multiplies one complex number to another and returns the result
Complex operator/(const Complex& lhs, const Complex& rhs); //non-member function, division operator that divides one complex number to another and returns the result

Complex::Complex(const double real)
  : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
  : re(real), im(imaginary)
{
}

#endif
