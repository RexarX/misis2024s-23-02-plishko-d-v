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
  BitSet(BitSet&& lhs);
  ~BitSet();

  BitSet& operator=(const BitSet& lhs);
  BitSet& operator=(BitSet&& lhs) noexcept;

  int32_t Size() const noexcept { return size_ ; }
  void Resize(const int32_t& size);
  void Set(const int32_t& index, const bool& value);
  uint32_t Get(const int32_t& index) const;
  void Clear() noexcept;

private:
  std::vector<uint32_t> data_;
  int32_t size_ = 0;
};