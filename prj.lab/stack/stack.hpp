#pragma once

#include <cstddef>

struct Complex;

class StackArr
{
public:
  StackArr();
  StackArr(const StackArr& lhs);
  ~StackArr();

  StackArr& operator=(const StackArr& lhs);

  bool operator==(const StackArr& lhs) const;

  const Complex& Top();
  void Push(const Complex& lhs);
  void Pop() noexcept;
  bool IsEmpty() noexcept;

private:
  void ChangeCapacity(const std::ptrdiff_t& newCapacity);

private:
  Complex* data_ = nullptr;

  std::ptrdiff_t top_ = -1;
  std::ptrdiff_t capacity_ = 2;
};