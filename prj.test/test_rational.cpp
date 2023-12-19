#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <rational/rational.cpp>

bool testParse(const std::string& str) {
  std::istringstream istrm(str);
  Rational q;
  istrm >> q;
  bool stream_good = !istrm.fail() || (istrm.eof() && !istrm.fail());
  if (stream_good) {
    std::cout << "Read success: " << str << " -> " << q << '\n';
  }
  else {
    std::cout << "Read error : " << str << " -> " << q << '\n';
  }
  return stream_good;
}

TEST_CASE("rational ctor") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(3);
  CHECK(3 == r_int.num());
  CHECK(1 == r_int.den());

  Rational q(2, -3);
  CHECK(-2 == q.num());
  CHECK(3 == q.den());

  CHECK_THROWS(Rational(1, 0));

  CHECK(testParse("1/2"));
  CHECK(testParse("1/0") == false);
}

TEST_CASE("rational bool operators") {
  Rational q(2, -3);
  CHECK(1 == (q == Rational(-2, 3)));
  CHECK(1 == (q != Rational(2)));

  CHECK(Rational(1, 2) >= q);
  CHECK(Rational(-2, 3) >= q);
  CHECK(Rational(-3, 4) <= q);
  CHECK(Rational(-2, 3) <= q);

  CHECK(Rational(1, 2) > q);
  CHECK(Rational(-3, 4) < q);
}

TEST_CASE("rational arithmetic operators") {
  Rational q(2, -3);

  q += Rational(-2, 3);
  CHECK(Rational(-4, 3) == q);
  CHECK(Rational(-6, 3) == (q + Rational(-2, 3)));

  q -= Rational(-2, 3);
  CHECK(Rational(-2, 3) == q);
  CHECK(Rational(-1, 3) == (q - Rational(-1, 3)));

  q *= Rational(-2, 3);
  CHECK(Rational(4, 9) == q);
  CHECK(Rational(-4, 27) == (q * Rational(-1, 3)));

  q /= Rational(-2, 3);
  CHECK(Rational(6, 18) == q);
  CHECK(Rational(18, 18) == (q / Rational(1, 3)));
}