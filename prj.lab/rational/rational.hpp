#include <sstream>
#include <cstdint>

class Rational {
public:
  Rational() = default;
  Rational(const Rational&) = default;
  explicit Rational(const std::int64_t num);
  Rational(const std::int64_t num, const std::int64_t den);
  ~Rational() = default;

  std::int64_t num() const { return num_; }
  std::int64_t den() const { return den_; }

  Rational& operator=(const Rational&) = default;

  bool operator==(const Rational& lhs) const { return num_ * lhs.den_ == lhs.num_ * den_; }
  bool operator!=(const Rational& lhs) const { return !operator==(lhs); }
  bool operator>(const Rational& lhs) const { return num_ * lhs.den_ > lhs.num_ * den_; }
  bool operator<(const Rational& lhs) const { return num_ * lhs.den_ < lhs.num_ * den_; }
  bool operator>=(const Rational& lhs) const { return operator==(lhs) || operator>(lhs); }
  bool operator<=(const Rational& lhs) const { return operator==(lhs) || operator<(lhs); }

  Rational operator-() const noexcept { return { -num_, den_ }; }

  Rational& operator+=(const Rational& lhs);
  Rational& operator+=(const std::int64_t& lhs) { return operator+=(Rational(lhs)); }
  Rational& operator-=(const Rational& lhs);
  Rational& operator-=(const std::int64_t& lhs) { return operator-=(Rational(lhs)); }
  Rational& operator*=(const Rational& lhs);
  Rational& operator*=(const std::int64_t& lhs) { return operator*=(Rational(lhs)); }
  Rational& operator/=(const Rational& lhs);
  Rational& operator/=(const std::int64_t& lhs) { return operator/=(Rational(lhs)); }

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);

private:
  std::int64_t num_ = 0;
  std::int64_t den_ = 1;
};

inline Rational operator+(const Rational& lhs, const Rational& rhs);
inline Rational operator-(const Rational& lhs, const Rational& rhs);
inline Rational operator*(const Rational& lhs, const Rational& rhs);
inline Rational operator/(const Rational& lhs, const Rational& rhs);

inline Rational operator+(const Rational& lhs, const std::int64_t& rhs) { return operator+(lhs, Rational(rhs)); }
inline Rational operator-(const Rational& lhs, const std::int64_t& rhs) { return operator-(lhs, Rational(rhs)); }
inline Rational operator*(const Rational& lhs, const std::int64_t& rhs) { return operator*(lhs, Rational(rhs)); }
inline Rational operator/(const Rational& lhs, const std::int64_t& rhs) { return operator/(lhs, Rational(rhs)); }

inline Rational operator+(const std::int64_t& lhs, const Rational& rhs) { return operator+(Rational(lhs), rhs); }
inline Rational operator-(const std::int64_t& lhs, const Rational& rhs) { return operator-(Rational(lhs), rhs); }
inline Rational operator*(const std::int64_t& lhs, const Rational& rhs) { return operator*(Rational(lhs), rhs); }
inline Rational operator/(const std::int64_t& lhs, const Rational& rhs) { return operator/(Rational(lhs), rhs); }
