#pragma once 

#include <vector>
#include <cstdint>
#include <stdexcept>

class BitSet
{
public:
  BitSet() = default;
  BitSet(const int32_t& size);
  BitSet(const BitSet& copy);
  BitSet(BitSet&& rhs);
  ~BitSet();

  BitSet& operator=(const BitSet& rhs);
  BitSet& operator=(BitSet&& rhs) noexcept;

  const bool& operator[](const int32_t& index) const;
  bool operator[](const int32_t& index);

  BitSet& operator&(const BitSet& rhs);
  BitSet& operator|(const BitSet& rhs);
  BitSet& operator^(const BitSet& rhs);
  BitSet& operator<<(const int32_t& shift);
  BitSet& operator>>(const int32_t& shift);
  BitSet& operator~();
  BitSet& operator!();

  int32_t Size() const noexcept { return size_ ; }
  void Resize(const int32_t& size);
  void Set(const int32_t& index, const bool& value);
  uint32_t Get(const int32_t& index) const;
  void Clear() noexcept;

private:
  std::vector<uint32_t> data_;
  int32_t size_ = 0;
};