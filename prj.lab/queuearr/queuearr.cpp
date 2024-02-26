#include <queuearr/queuearr.hpp>

#include <stdexcept>


QueueArr::QueueArr()
  : data_(new Complex[capacity_]())
{
}

QueueArr::QueueArr(const QueueArr& lhs)
  : size_(lhs.size_), capacity_(lhs.capacity_), head_(lhs.head_), tail_(lhs.tail_)
{
  if (data_ == nullptr) { data_ = new Complex[capacity_](); }
  std::copy(lhs.data_, lhs.data_ + size_, data_);
}

QueueArr::~QueueArr()
{
  Clear();
}

QueueArr& QueueArr::operator=(const QueueArr& lhs)
{
  if (data_ == nullptr) { data_ = new Complex[capacity_](); }
  std::copy(lhs.data_, lhs.data_ + size_, data_);
  head_ = lhs.head_;
  tail_ = lhs.tail_;
  return *this;
}

void QueueArr::ChangeCapacity(const std::ptrdiff_t& newCapacity)
{
  Complex* newQueueArr = new Complex[newCapacity]();
  if (newCapacity <= size_) { size_ = newCapacity; }
  std::move(data_, data_ + size_, newQueueArr);
  delete[] data_;
  data_ = newQueueArr;
  capacity_ = newCapacity;
  tail_ = &data_[size_];
}

bool QueueArr::IsEmpty() const noexcept
{
  return 0 == size_;
}

void QueueArr::Push(const Complex& value)
{
  if (size_ - 1 == capacity_) { ChangeCapacity(2 * capacity_); }
  ++size_;
  data_[size_ - 1] = value;
  tail_ = &data_[size_ - 1];
  if (size_ == 1) { head_ = &data_[size_ - 1]; }
}

void QueueArr::Pop() noexcept
{
  if (!IsEmpty()) {
    --size_;
    tail_ = &data_[size_ - 1];
  }
  tail_ = nullptr;
  head_ = nullptr;
}

Complex& QueueArr::Top()
{
  if (IsEmpty()) { throw std::logic_error("QueueArr - try get top form empty queue."); }
  return data_[size_];
}

const Complex& QueueArr::Top() const
{
  if (IsEmpty()) { throw std::logic_error("QueueArr - try get top form empty queue."); }
  return data_[size_];
}

void QueueArr::Clear() noexcept
{
  while (!IsEmpty()) {
    Pop();
  }
}