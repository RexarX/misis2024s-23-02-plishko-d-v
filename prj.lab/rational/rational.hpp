#include <sstream>
#include <cstdint>

class Rational {
public:
  Rational() = default;
  explicit Rational(const int64_t num);
  Rational(const int64_t num, const int64_t den);
  ~Rational() = default;

  int64_t num() const { return num_; }
  int64_t den() const { return den_; }

  bool operator==(const Rational& lhs) const { return num_ * lhs.den_ == lhs.num_ * den_; }
  bool operator!=(const Rational& lhs) const { return !operator==(lhs); }
  bool operator>(const Rational& lhs) const { return num_ * lhs.den_ > lhs.num_ * den_; }
  bool operator<(const Rational& lhs) const { return num_ * lhs.den_ < lhs.num_ * den_; }
  bool operator>=(const Rational& lhs) const { return operator==(lhs) || operator>(lhs); }
  bool operator<=(const Rational& lhs) const { return operator==(lhs) || operator<(lhs); }

  Rational& operator+=(const Rational& lhs);
  Rational& operator+=(const int64_t& lhs) { return operator+=(Rational(lhs)); }
  Rational& operator-=(const Rational& lhs);
  Rational& operator-=(const int64_t& lhs) { return operator-=(Rational(lhs)); }
  Rational& operator*=(const Rational& lhs);
  Rational& operator*=(const int64_t& lhs) { return operator*=(Rational(lhs)); }
  Rational& operator/=(const Rational& lhs);
  Rational& operator/=(const int64_t& lhs) { return operator/=(Rational(lhs)); }

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);

private:
  int64_t num_ = 0;
  int64_t den_ = 1;
};

inline Rational operator+(const Rational& lhs, const Rational& rhs);
inline Rational operator-(const Rational& lhs, const Rational& rhs);
inline Rational operator*(const Rational& lhs, const Rational& rhs);
inline Rational operator/(const Rational& lhs, const Rational& rhs);