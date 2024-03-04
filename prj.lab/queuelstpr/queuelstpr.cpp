#include <queuelstpr/queuelstpr.hpp>

#include <algorithm>
#include <stdexcept>

QueueLstPr::QueueLstPr(const QueueLstPr& lhs)
{
  Node* temp = lhs.head_;
  while (temp != nullptr) {
    Push(temp->val);
    temp = temp->next;
  }
}

QueueLstPr::QueueLstPr(const QueueLstPr&& lhs)
{
  Node* temp = lhs.head_;
  while (temp != nullptr) {
    Push(temp->val);
    temp = temp->next;
  }
}

QueueLstPr::~QueueLstPr()
{
  Clear();
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& lhs)
{
  Clear();
  Node* temp = (lhs.head_);
  while (temp != nullptr) {
    Push(temp->val);
    temp = temp->next;
  }
  return *this;
}

bool QueueLstPr::IsEmpty() const noexcept
{
  return nullptr == head_;
}

void QueueLstPr::Push(const float& value)
{
  Node* temp = head_;
  if (!IsEmpty()) {
    while (tail_->next != nullptr) {
      if (temp->val > tail_->val) {
      }
      else if (temp->val < tail_->val) {
      }
    }
  }
  else { head_ = (temp); }
  tail_ = (temp);
  delete temp;
  temp = nullptr;
}

void QueueLstPr::Pop() noexcept
{
  if (!IsEmpty()) {
    Node* temp = (head_);
    head_ = head_->next;
    if (temp == tail_) { tail_ = (nullptr); }
    delete temp;
    temp = nullptr;
  }
}

float& QueueLstPr::Top()
{
  if (IsEmpty()) { throw std::logic_error("QueueLstPr - try get top form empty queue."); }
  return head_->val;
}

const float& QueueLstPr::Top() const
{
  if (IsEmpty()) { throw std::logic_error("QueueLstPr - try get top form empty queue."); }
  return head_->val;
}

void QueueLstPr::Clear() noexcept
{
  while (!IsEmpty()) {
    Pop();
  }
}