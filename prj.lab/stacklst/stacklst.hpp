#pragma once

#include <cstddef>

#include <complex/complex.cpp>


class StackLst {
public:
  StackLst() = default;
  StackLst(const StackLst& lhs);
  ~StackLst();

  StackLst& operator=(const StackLst& lhs);

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

  std::ptrdiff_t size_ = 0;
  Node* head_ = nullptr;
};