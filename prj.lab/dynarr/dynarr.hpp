#pragma once

#include <cstddef>
#include <memory>

class DynArr
{
public:
  DynArr();
  DynArr(const DynArr& rhs);
  DynArr(DynArr&& rhs) noexcept;
  DynArr(const std::ptrdiff_t size);
  ~DynArr() = default;

  std::ptrdiff_t Size() const noexcept { return size_; }

  void Resize(const std::ptrdiff_t size);

  DynArr& operator=(const DynArr& rhs);
  DynArr& operator=(DynArr&& rhs) noexcept;

  const float& operator[](const std::ptrdiff_t index) const;
  float& operator[](const std::ptrdiff_t index);

  bool operator==(const DynArr& rhs) const;
  bool operator!=(const DynArr& rhs) const { return !operator==(rhs); }

private:
  void ChangeCapacity(const std::ptrdiff_t capacity);

  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 2;
  std::unique_ptr<float[]> data_;
};