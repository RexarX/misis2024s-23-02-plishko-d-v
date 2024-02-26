#include "stacklst.hpp"

#include <stdexcept>


StackLst::StackLst(const StackLst& lhs)
{
  Node* temp = lhs.head_;
  while (temp != nullptr) {
    Push(temp->val);
    temp = temp->next;
  }
}

StackLst::~StackLst()
{
  Clear();
}

StackLst& StackLst::operator=(const StackLst& lhs)
{
  Clear();
  Node* temp = lhs.head_;
  while (temp != nullptr) {
    Push(temp->val);
    temp = temp->next;
  }
  return *this;
}

bool StackLst::IsEmpty() const noexcept
{
  return nullptr == head_;
}

void StackLst::Pop() noexcept
{
  if (!IsEmpty()) {
    Node* deleted = head_;
    head_ = head_->next;
    delete deleted;
  }
}

void StackLst::Push(const Complex& value)
{
  Node* temp = new Node{ value, nullptr };
  head_ = temp;
  temp = nullptr;
}

Complex& StackLst::Top()
{
  if (IsEmpty()) { throw std::logic_error("StackLst - try get top form empty stack."); }
  return head_->val;
}

const Complex& StackLst::Top() const
{
  if (IsEmpty()) { throw std::logic_error("StackLst - try get top form empty stack."); }
  return head_->val;
}

void StackLst::Clear() noexcept
{
  while (!IsEmpty()) {
    Pop();
  }
}