#pragma once

#include <memory>

class QueueLstPr
{
public:
  QueueLstPr() = default;
  QueueLstPr(const QueueLstPr& lhs);
  QueueLstPr(const QueueLstPr&& lhs);
  ~QueueLstPr();

  QueueLstPr& operator=(const QueueLstPr& lhs);

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const float& val);

  float& Top();
  const float& Top() const;

  void Clear() noexcept;

private:
  struct Node
  {
    float val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};