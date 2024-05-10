#pragma once

#include <cstddef>

class QueueLstPr
{
public:
  QueueLstPr() = default;
  QueueLstPr(const QueueLstPr& copy);
  QueueLstPr(QueueLstPr&& src) noexcept;
  ~QueueLstPr();

  QueueLstPr& operator=(const QueueLstPr& copy);
  QueueLstPr& operator=(QueueLstPr&& src) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;
  void Push(const float value);
  void Clear() noexcept;

  float Top();
  const float Top() const;

private:
  struct Node {
    float val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};