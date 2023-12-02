#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <dynarr/dynarr.cpp>

TEST_CASE("DynamicArray ctor") {
  DynArr<int> q(2);
  CHECK_THROWS(q.Pop_back());

  q.Push_back(10);
  q.Push_back(1);
  q.Push_back(2);
  q.Push_back(3);

  DynArr<int> w;
  w = q;
  CHECK(w == q);
 
  CHECK(10 == q[0]);
  CHECK(10 == w[0]);

  q.Pop_back();
  CHECK(2 == q[2]);

  q.Erase(3);
  q.Push_back(4);
  CHECK(4 == q[2]);

  q.Clear();
  CHECK(0 == q.Size());

  q.Resize(10);
  CHECK(10 == q.Capacity());

  CHECK_THROWS(q[100]);
  CHECK_THROWS(q[-1]);
}