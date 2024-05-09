#include <dynarr/dynarr.hpp>
#include <iostream>
#include <stdexcept>

DynArr::DynArr()
  : data_(std::make_unique<float[]>(capacity_))
{
}

DynArr::DynArr(const DynArr& rhs)
  : size_(rhs.size_), capacity_(rhs.capacity_), data_(std::make_unique<float[]>(size_))
{
  std::memcpy(data_.get(), rhs.data_.get(), size_ * sizeof(float));
}

DynArr::DynArr(DynArr&& other) noexcept
{
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

DynArr::DynArr(const std::ptrdiff_t size)
{
  if (size <= 0) { throw std::invalid_argument("Positive size is required!"); }
  size_ = size;
  capacity_ = size_;
  data_ = std::make_unique<float[]>(size_);
  std::memset(data_.get(), 0.0f, size_ * sizeof(float));
}

void DynArr::ChangeCapacity(const std::ptrdiff_t capacity)
{
  if (capacity <= 0) { throw std::invalid_argument("Positive capacity is required!"); }
  if (capacity < size_) { size_ = capacity; }
  else {
    std::unique_ptr<float[]> newData = std::make_unique<float[]>(capacity);
    std::memmove(newData.get(), data_.get(), size_ * sizeof(float));
    data_ = std::move(newData);
    newData.release();
  }
  capacity_ = capacity;
}

void DynArr::Resize(const std::ptrdiff_t size)
{
  if (size <= 0) { throw std::invalid_argument("Positive size is required!"); }
  if (size > capacity_) { ChangeCapacity(size); }
  std::memset(data_.get() + size_ + 1, 0.0f, size);
  size_ = size;
}

DynArr& DynArr::operator=(const DynArr& rhs)
{
  if (this != &rhs) {
    if (capacity_ < rhs.size_) { ChangeCapacity(rhs.capacity_); }
    std::memcpy(data_.get(), rhs.data_.get(), rhs.size_ * sizeof(float));
    size_ = rhs.size_;
  }
  return *this;
}

DynArr& DynArr::operator=(DynArr&& rhs) noexcept
{
  if (this != &rhs) {
    if (capacity_ < rhs.size_) { ChangeCapacity(rhs.capacity_); }
    std::memmove(data_.get(), rhs.data_.get(), rhs.size_ * sizeof(float));
    size_ = rhs.size_;
    rhs.data_.release();
    rhs.size_ = 0;
    rhs.capacity_ = 0;
  }
  return *this;
}

const float& DynArr::operator[](const std::ptrdiff_t index) const
{
  if (index >= size_ || index < 0) { throw std::invalid_argument("Index out of range!"); }
  return *(data_.get() + index);
}

float& DynArr::operator[](const std::ptrdiff_t index)
{
  if (index >= size_ || index < 0) { throw std::invalid_argument("Index out of range!"); }
  return *(data_.get() + index);
}

bool DynArr::operator==(const DynArr& rhs) const
{
  if (size_ != rhs.size_) { return false; }
  for (std::ptrdiff_t i = 0; i < size_; ++i) {
    if (data_[i] != rhs.data_[i]) { return false; }
  }
  return true;
}
