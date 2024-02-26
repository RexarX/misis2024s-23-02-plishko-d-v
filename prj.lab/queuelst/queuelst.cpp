#include <queuelst/queuelst.hpp>

#include <stdexcept>

QueueLst::QueueLst(const QueueLst& lhs)
{
  Node* temp = lhs.head_;
  while (temp != nullptr) {
    Push(temp->val);
    temp = temp->next;
  }
}

QueueLst::~QueueLst()
{
  Clear();
}

QueueLst& QueueLst::operator=(const QueueLst& lhs)
{
  Clear();
  Node* temp = lhs.head_;
  while (temp != nullptr) {
    Push(temp->val);
    temp = temp->next;
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
    temp = nullptr;
  }
}

Complex& QueueLst::Top()
{
  if (IsEmpty()) { throw std::logic_error("QueueLst - try get top form empty queue."); }
  return head_->val;
}

const Complex& QueueLst::Top() const
{
  if (IsEmpty()) { throw std::logic_error("QueueLst - try get top form empty queue."); }
  return head_->val;
}

void QueueLst::Clear() noexcept
{
  while (!IsEmpty()) {
    Pop();
  }
}