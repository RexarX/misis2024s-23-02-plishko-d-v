#include "queuelstpr.hpp"

#include <stdexcept>

QueueLstPr::QueueLstPr(const QueueLstPr& copy)
{
  Node* temp = copy.head_;
  while (temp != nullptr) {
    Push(temp->val);
    temp = temp->next;
  }
}

QueueLstPr::QueueLstPr(QueueLstPr&& src) noexcept
{
  std::swap(head_, src.head_);
  std::swap(tail_, src.tail_);
}

QueueLstPr::~QueueLstPr()
{
  Clear();
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& copy)
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

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& src) noexcept
{
  if (this != &src) {
    head_ = src.head_;
    tail_ = src.tail_;
    src.head_ = nullptr;
    src.tail_ = nullptr;
  }
  return *this;
}

bool QueueLstPr::IsEmpty() const noexcept
{
  return nullptr == head_;
}

void QueueLstPr::Push(const float value)
{
  if (IsEmpty()) { head_ = new Node{ value, head_ }; }
  else {
    if (head_->val > value) { head_ = new Node{ value, head_ }; }
    else {
      Node* temp = head_;
      while (temp->next != nullptr && temp->next->val < value) {
        temp = temp->next;
      }
      temp->next = new Node{ value, temp->next };
    }
  }
}

void QueueLstPr::Pop() noexcept
{
  if (!IsEmpty()) {
    Node* temp = head_;
    head_ = head_->next;
    if (temp == tail_) { tail_ = nullptr; }

    delete temp;
  }
}

float QueueLstPr::Top()
{
  if (IsEmpty()) { throw std::logic_error("Queue is empty!"); }
  return head_->val;
}

const float QueueLstPr::Top() const
{
  if (IsEmpty()) { throw std::logic_error("Queue is empty!"); }
  return head_->val;
}

void QueueLstPr::Clear() noexcept
{
  while (!IsEmpty()) {
    Pop();
  }
}