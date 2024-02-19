#include "stacklst.hpp"

#include <stdexcept>
#include <vector>


StackLst::StackLst(const StackLst& lhs)
  : size_(lhs.size_)
{
  Node* head = lhs.head_;
  std::vector<Complex> vec;
  for (int i = 0; i < size_; ++i) {
    vec.push_back(head->val);
    head = head->next;
  }
  for (int i = size_ - 1; i >= 0; --i) {
    Push(vec[i]);
  }
}

StackLst::~StackLst()
{
  delete head_;
  head_ = nullptr;
  size_ = 0;
}

StackLst& StackLst::operator=(const StackLst& lhs) {
  StackLst temp;
  Node* head = lhs.head_;
  for (int i = 0; i < lhs.size_; ++i) {
    temp.Push(head->val);
    head = head->next;
  }
  head = temp.head_;
  for (int i = 0; i < lhs.size_; ++i) {
    Push(head->val);
    head = head->next;
  }
  return *this;
}

bool StackLst::IsEmpty() const noexcept
{
  return nullptr == head_;
}

void StackLst::Pop() noexcept
{
  if (size_ > 1) {
    Node* data = head_;
    head_ = head_->next;
    delete data;
    --size_;
  } else if (size_ == 1) {
    delete head_;
    head_ = nullptr;
    size_ = 0;
  }
}

void StackLst::Push(const Complex& val)
{
  Node* head = new Node;
  head->val = val;
  if (size_ != 0) { head->next = head_; } 
  else { head->next = nullptr; }
  head_ = head;
  ++size_;
  head_ = new Node{ val, head_ };
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