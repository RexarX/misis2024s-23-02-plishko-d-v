#include "bitset.hpp"

BitSet::BitSet(const int32_t& size)
  : size_(size)
{
  data_.resize((size - 1) / 32 + 1);
}

BitSet::BitSet(const BitSet& copy)
  : data_(copy.data_), size_(copy.size_)
{
}

BitSet::BitSet(BitSet&& rhs)
  :data_(std::move(rhs.data_)), size_(rhs.size_)
{
  rhs.size_ = 0;
}

BitSet::~BitSet()
{
  data_.clear();
  size_ = 0;
}

BitSet& BitSet::operator=(const BitSet& rhs) noexcept
{
  data_ = rhs.data_;
  return *this;
}

BitSet& BitSet::operator=(BitSet&& rhs) noexcept
{
  data_ = std::move(rhs.data_);
  size_ = rhs.size_;
  rhs.size_ = 0;
  return *this;
}

const bool& BitSet::operator[](const int32_t& index) const
{
  if (index < 0) { throw std::out_of_range("Invalid index!"); }
  return (data_[index / 32] & (1 << (31 - index % 32))) != 0;
}

bool BitSet::operator[](const int32_t& index)
{
  if (index < 0) { throw std::out_of_range("Invalid index!"); }
  return (data_[index / 32] & (1 << (31 - index % 32))) != 0;
}

BitSet& BitSet::operator&(const BitSet& rhs)
{
  for (int32_t i = 0; i < data_.size(); ++i) {
    data_[i] &= rhs.data_[i];
  }
  return *this;
}

BitSet& BitSet::operator|(const BitSet& rhs)
{
  for (int32_t i = 0; i < data_.size(); ++i) {
    data_[i] |= rhs.data_[i];
  }
  return *this;
}

BitSet& BitSet::operator^(const BitSet& rhs)
{
  for (int32_t i = 0; i < data_.size(); ++i) {
    data_[i] ^= rhs.data_[i];
  }
  return *this;
}

BitSet& BitSet::operator<<(const int32_t& shift)
{
  for (int32_t i = 0; i < data_.size(); ++i) {
    data_[i] = (data_[i] << shift) | (data_[i] >> (32 - shift));
  }
  return *this;
}

BitSet& BitSet::operator>>(const int32_t& shift)
{
  for (int32_t i = 0; i < data_.size(); ++i) {
    data_[i] = (data_[i] >> shift) | (data_[i] << (32 - shift));
  }
  return *this;
}

BitSet& BitSet::operator~()
{
  for (int32_t i = 0; i < data_.size(); ++i) {
    data_[i] = ~data_[i];
  }
  return *this;
}

BitSet& BitSet::operator!()
{
  for (int32_t i = 0; i < data_.size(); ++i) {
    data_[i] != data_[i];
  }
  return *this;
}

void BitSet::Resize(const int32_t& size)
{
  if (size == size_) { return; }
  if (size < 0) { throw std::out_of_range("Invalid size!"); }
  data_.resize((size - 1) / 32 + 1);
  size_ = size;
}

void BitSet::Set(const int32_t& index, const bool& value)
{
  if (index < 0) { throw std::out_of_range("Invalid index!"); }
  if (value) { data_[index / 32] |= 1 << (31 - index % 32); }
  else { data_[index / 32] &= ~(1 << (31 - index % 32)); }
}

uint32_t BitSet::Get(const int32_t& index) const
{
  if (index < 0) { throw std::out_of_range("Invalid index!"); }
  return (data_[index / 32] & (1 << ( 31 - index % 32))) != 0;
}

void BitSet::Clear() noexcept
{
  data_.clear();
  size_ = 0;
}