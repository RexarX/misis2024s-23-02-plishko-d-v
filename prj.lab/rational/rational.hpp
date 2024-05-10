#include <sstream>
#include <cstdint>

class Rational
{
public:
  Rational() = default;
  Rational(const Rational& copy) = default;
  Rational(Rational&& src) noexcept = default;
  Rational(const int64_t num);
  Rational(const int64_t num, const int64_t den);
  ~Rational() = default;

  int64_t num() const noexcept  { return num_; }
  int64_t den() const noexcept  { return den_; }

  Rational& operator=(const Rational& copy) = default;
  Rational& operator=(Rational&& src) noexcept = default;

  bool operator==(const Rational& value) const noexcept { return num_ * value.den_ == value.num_ * den_; }
  bool operator==(const int64_t value) const noexcept { return num_ == value * den_; };
  bool operator!=(const Rational& value) const noexcept { return !operator==(value); }
  bool operator!=(const int64_t value) const noexcept { return !operator==(value); }
  bool operator>(const Rational& value) const noexcept { return num_ * value.den_ > value.num_ * den_; }
  bool operator>(const int64_t value) const noexcept { return num_ > value * den_; }
  bool operator<(const Rational& value) const noexcept { return num_ * value.den_ < value.num_ * den_; }
  bool operator<(const int64_t value) const noexcept { return num_ < value * den_; }
  bool operator>=(const Rational& value) const noexcept { return operator==(value) || operator>(value); }
  bool operator<=(const Rational& value) const noexcept { return operator==(value) || operator<(value); }

  Rational operator-() const noexcept { return { -num_, den_ }; }

  Rational& operator+=(const Rational& value) noexcept;
  Rational& operator+=(const int64_t value) noexcept { return operator+=(Rational(value)); }
  Rational& operator-=(const Rational& value) noexcept { return operator+=(-value); }
  Rational& operator-=(const int64_t value) noexcept { return operator-=(Rational(value)); }
  Rational& operator*=(const Rational& value) noexcept;
  Rational& operator*=(const int64_t value) noexcept { return operator*=(Rational(value)); }
  Rational& operator/=(const Rational& value);
  Rational& operator/=(const int64_t value) { return operator/=(Rational(value)); }

  std::ostream& writeTo(std::ostream& ostrm) const noexcept;
  std::istream& readFrom(std::istream& istrm) noexcept;

  void CheckSign() noexcept;
  void SimplifyFraction() noexcept;

private:
  int64_t num_ = 0;
  int64_t den_ = 1;
};

inline Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
inline Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return operator+(lhs, -rhs); }
inline Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
inline Rational operator/(const Rational& lhs, const Rational& rhs);

inline Rational operator+(const Rational& lhs, const int64_t rhs) noexcept { return operator+(lhs, Rational(rhs)); }
inline Rational operator-(const Rational& lhs, const int64_t rhs) noexcept { return operator-(lhs, Rational(rhs)); }
inline Rational operator*(const Rational& lhs, const int64_t rhs) noexcept { return operator*(lhs, Rational(rhs)); }
inline Rational operator/(const Rational& lhs, const int64_t rhs) { return operator/(lhs, Rational(rhs)); }

inline Rational operator+(const int64_t lhs, const Rational& rhs) noexcept { return operator+(Rational(lhs), rhs); }
inline Rational operator-(const int64_t lhs, const Rational& rhs) noexcept { return operator-(Rational(lhs), rhs); }
inline Rational operator*(const int64_t lhs, const Rational& rhs) noexcept { return operator*(Rational(lhs), rhs); }
inline Rational operator/(const int64_t lhs, const Rational& rhs) { return operator/(Rational(lhs), rhs); }

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept
{
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept
{
  return rhs.readFrom(istrm);
}