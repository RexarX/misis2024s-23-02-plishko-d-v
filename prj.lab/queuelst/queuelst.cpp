#include "queuelst.hpp"

#include <stdexcept>

QueueLst::QueueLst(const QueueLst& copy)
{
  Node* temp = copy.head_;
  while (temp != nullptr) {
    Push(temp->val);
    temp = temp->next;
  }
}

QueueLst::QueueLst(QueueLst&& src) noexcept
{
  std::swap(head_, src.head_);
  std::swap(tail_, src.tail_);
}

QueueLst::~QueueLst()
{
  Clear();
}

QueueLst& QueueLst::operator=(const QueueLst& copy)
{
  if (this != &copy) {
    Clear();
    Node* temp = copy.head_;
    while (temp != nullptr) {
      Push(temp->val);
      temp = temp->next;
    }
  }
  return *this;
}

QueueLst& QueueLst::operator=(QueueLst&& src) noexcept
{
  if (this != &src) {
    head_ = src.head_;
    tail_ = src.tail_;
    src.head_ = nullptr;
    src.tail_ = nullptr;
  }
  return *this;
}

bool QueueLst::IsEmpty() const noexcept
{
  return nullptr == head_;
}

void QueueLst::Push(const Complex& value)
{
  Node* temp = new Node{ value, nullptr };
  if (!IsEmpty()) { tail_->next = temp; } 
  else { head_ = temp; }

  tail_ = temp;
  temp = nullptr;
}

void QueueLst::Pop() noexcept
{
  if (!IsEmpty()) {
    Node* temp = head_;
    head_ = head_->next;
    if (temp == tail_) { tail_ = nullptr; }

    delete temp;
  }
}

Complex& QueueLst::Top()
{
  if (IsEmpty()) { throw std::logic_error("Queue is empty!"); }
  return head_->val;
}

const Complex& QueueLst::Top() const
{
  if (IsEmpty()) { throw std::logic_error("Queue is empty!"); }
  return head_->val;
}

void QueueLst::Clear() noexcept
{
  while (!IsEmpty()) {
    Pop();
  }
}