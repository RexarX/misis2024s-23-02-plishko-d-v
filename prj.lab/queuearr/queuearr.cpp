#include "queuearr.hpp"

#include <stdexcept>

QueueArr::QueueArr()
  : data_(std::make_unique<Complex[]>(capacity_))
{
}

QueueArr::QueueArr(const QueueArr& src)
  : head_(0), tail_(0), data_(std::make_unique<Complex[]>(src.head_ - src.tail_)),
    capacity_(src.head_ - src.tail_)
{
  for (uint32_t i = 0; i < capacity_; ++i) {
    Push(src.data_[(src.tail_ + i) % src.capacity_]);
  }
}

QueueArr::QueueArr(QueueArr&& src) noexcept
{
  std::swap(data_, src.data_);
  std::swap(head_, src.head_);
  std::swap(tail_, src.tail_);
  std::swap(capacity_, src.capacity_);
}

QueueArr& QueueArr::operator=(const QueueArr& value)
{
  if (this != &value) {
    if (capacity_ < value.head_ - value.tail_) {
      Clear();
      data_ = std::make_unique<Complex[]>((value.head_ - value.tail_) * 2);
    }
    head_ = 0;
    tail_ = 0;
    for (uint32_t i = 0; i < value.head_ - value.tail_; ++i) {
      Push(value.data_[(value.tail_ + i) % value.capacity_]);
    }
  }
  return *this;
}

QueueArr& QueueArr::operator=(QueueArr&& value) noexcept
{
  if (this != &value) {
    data_ = std::move(value.data_);
    value.data_.release();
    head_ = value.head_;
    tail_ = value.tail_;
    capacity_ = value.capacity_;
    value.head_ = 0;
    value.tail_ = 0;
    value.capacity_ = 0;
  }
  return *this;
}

bool QueueArr::IsEmpty() const noexcept
{
  return head_ == tail_;
}

void QueueArr::Push(const Complex& value)
{
  if (!IsEmpty() && (head_ % capacity_) == (tail_ % capacity_)) {
    ChangeCapacity(capacity_ * 2);
  }
  *(data_.get() + (head_ % capacity_)) = value;
  ++head_;
}

void QueueArr::Pop() noexcept
{
  if (!IsEmpty()) {
    ++tail_;
  }
}

Complex& QueueArr::Top()
{
  if (IsEmpty()) {
    throw std::out_of_range("Cannot get an element of empty queue!");
  }
  return *(data_.get() + (tail_ % capacity_));
}

const Complex& QueueArr::Top() const
{
  if (IsEmpty()) {
    throw std::out_of_range("Cannot get an element of empty queue!");
  }
  return *(data_.get() + (tail_ % capacity_));
}

void QueueArr::ChangeCapacity(const std::ptrdiff_t capacity)
{
  if (capacity <= 0) { throw std::invalid_argument("Positive capacity is required!"); }
  std::unique_ptr<Complex[]> newData = std::make_unique<Complex[]>(capacity);
  for (uint32_t i = 0; i < capacity_; ++i) {
    newData[i] = data_[(tail_ + i) % capacity_];
  }
  data_.reset();
  data_ = std::move(newData);
  newData.release();
  head_ -= tail_;
  tail_ = 0;
  capacity_ = capacity;
}

void QueueArr::Clear()
{
  while (!IsEmpty()) {
    Pop();
  }
}