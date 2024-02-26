#pragma once

#include <cstddef>

#include <complex/complex.cpp>


class QueueArr
{
public:
  QueueArr();
  QueueArr(const QueueArr& lhs);
  ~QueueArr();

  QueueArr& operator=(const QueueArr& lhs);

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  Complex& Top();
  const Complex& Top() const;

  void Clear() noexcept;

private:
  void ChangeCapacity(const std::ptrdiff_t& newCapacity);

private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 2;
  Complex* head_ = nullptr;
  Complex* tail_ = nullptr;

  Complex* data_ = nullptr;
};