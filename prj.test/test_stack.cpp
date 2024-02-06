#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <stack/stack.cpp>

TEST_CASE("StackArr ctor") {
  StackArr q;

  q.Push(Complex(1, 1));
  StackArr r(q);
  CHECK_EQ(r, q);
}

TEST_CASE("StackArr methods") {
  StackArr w;

  CHECK(w.IsEmpty());

  w.Push(Complex(1, 2));
  CHECK_EQ(Complex(1, 2), w.Top());

  w.Push(Complex(1, 1));
  w.Pop();
  CHECK_EQ(Complex(1, 2), w.Top());
}