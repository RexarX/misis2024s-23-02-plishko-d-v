#include "stack.hpp"
#include <iostream>
#include <algorithm>

#include <complex/complex.cpp>

StackArr::StackArr()
  : data_(new Complex[2]())
{
}

StackArr::StackArr(const StackArr& lhs)
	: top_(lhs.top_), data_(new Complex[lhs.capacity_]()), capacity_(lhs.capacity_)
{
  std::copy(lhs.data_, lhs.data_ + lhs.top_ + 1, data_);
}

StackArr::~StackArr()
{
  delete[] data_;
}

StackArr& StackArr::operator=(const StackArr& lhs)
{
  if (lhs.capacity_ > capacity_) { ChangeCapacity(lhs.capacity_); }
  std::copy(lhs.data_, lhs.data_ + lhs.top_ + 1, data_);
  top_ = lhs.top_;
  return *this;
}

bool StackArr::operator==(const StackArr& lhs) const
{
  for (int i = 0; i < lhs.top_ + 1; ++i) {
    if (data_[i] != lhs.data_[i]) { return false; }
  }
  return true;
}

void StackArr::ChangeCapacity(const std::ptrdiff_t& newCapacity)
{
  Complex* newStackArr = new Complex[newCapacity]();
  if (newCapacity < top_) { top_ = newCapacity; }
  std::move(data_, data_ + top_ + 1, newStackArr);
  delete[] data_;
  data_ = newStackArr;
  capacity_ = newCapacity;
}

const Complex& StackArr::Top()
{
  if (top_ != -1) { return data_[top_]; }
  throw ("Empty stack Top");
}

void StackArr::Push(const Complex& object)
{
  if (top_ == capacity_) { ChangeCapacity(2 * capacity_); }
  ++top_;
  data_[top_] = object;
}

void StackArr::Pop() noexcept
{
  if (top_ != -1) { --top_; }
}

bool StackArr::IsEmpty() noexcept
{
  return top_ == -1;
}