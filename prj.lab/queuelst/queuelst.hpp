#pragma once

#include <complex/complex.hpp>

#include <cstddef>

class QueueLst
{
public:
  QueueLst() = default;
  QueueLst(const QueueLst& copy);
  QueueLst(QueueLst&& src) noexcept;
  ~QueueLst();

  QueueLst& operator=(const QueueLst& copy);
  QueueLst& operator=(QueueLst&& src) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;
  void Push(const Complex& value);
  void Clear() noexcept;

  Complex& Top();
  const Complex& Top() const;

private:
  struct Node {
    Complex val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};