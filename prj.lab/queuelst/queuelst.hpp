#pragma once

#include <cstddef>

#include <complex/complex.cpp>


class QueueLst
{
public:
  QueueLst() = default;
  QueueLst(const QueueLst& lhs);
  ~QueueLst();

  QueueLst& operator=(const QueueLst& lhs);

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  Complex& Top();
  const Complex& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    Complex val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};