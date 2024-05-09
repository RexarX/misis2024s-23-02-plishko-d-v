#pragma once

#include <cstddef>
#include <memory>
#include <complex/complex.hpp>

class QueueArr
{
public:
  QueueArr();
  QueueArr(const QueueArr& src);
  QueueArr(QueueArr&& src) noexcept;
  ~QueueArr() = default;

  QueueArr& operator=(const QueueArr& src);
  QueueArr& operator=(QueueArr&& src) noexcept;

  bool IsEmpty() const noexcept;

  void Push(const Complex& value);
  void Pop() noexcept;
  void Clear();

  Complex& Top();
  const Complex& Top() const;

private:
  void ChangeCapacity(const std::ptrdiff_t capacity);

private:
  std::unique_ptr<Complex[]> data_;
  std::ptrdiff_t head_ = 0;
  std::ptrdiff_t tail_ = 0;
  std::ptrdiff_t capacity_ = 2;
};