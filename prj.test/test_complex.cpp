#include <complex/complex.hpp>
#include <iostream>

bool testParse(const std::string& str) noexcept {
  std::istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good() || istrm.eof()) { std::cout << "Read Success: "; }
  else { std::cout << "Read Error: "; }
  std::cout << "read " << z << " from " << str << '\n';
  return istrm.good();
}

int main() {
  Complex z(4.0);
  std::cout << "complex number: " << z << '\n';

  z += Complex(8.0, 3.0);
  std::cout << "complex += complex: " << z << '\n';
  z += 4.0;
  std::cout << "complex += real: " << z << '\n';
  z = Complex(8.0, 3.0) + Complex(4.0, 2.0);
  std::cout << "complex + complex: " << z << '\n';

  z -= Complex(8.0, 3.0);
  std::cout << "complex -= complex: " << z << '\n';
  z -= 4.0;
  std::cout << "complex += real: " << z << '\n';
  z = Complex(8.0, 3.0) - Complex(4.0, 2.0);
  std::cout << "complex - complex: " << z << '\n';

  z *= Complex(8.0, 3.0);
  std::cout << "complex *= complex: " << z << '\n';
  z *= 4.0;
  std::cout << "complex *= real: " << z << '\n';
  z = Complex(8.0, 3.0) * Complex(4.0, 2.0);
  std::cout << "complex * complex: " << z << '\n';

  z /= Complex(8.0, 3.0);
  std::cout << "complex /= complex: " << z << '\n';
  z /= 4.0;
  std::cout << "complex /= real: " << z << '\n';
  z = Complex(8.0, 3.0) / Complex(4.0, 2.0);
  std::cout << "complex / complex: " << z << '\n';

  testParse("{8.9,9}");
  testParse("{8.9, 9}");
  testParse("{8.9,9");
  return 0;
}
