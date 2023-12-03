#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <dynarr/dynarr.cpp>

TEST_CASE("DynamicArray ctor") {
  DynArr<int> q;
  DynArr<int> w;

  q.Push_back(10);

  w = q;
  CHECK(w == q);

  CHECK(10 == q[0]);
  CHECK(10 == w[0]);
}

TEST_CASE("DynamicArray methods") {
  DynArr<int> e;

  CHECK_THROWS(e.Pop_back());
  
  e.Push_back(10);
  e.Push_back(1);
  e.Push_back(2);
  e.Push_back(3);
  
  e.Pop_back();
  CHECK(2 == e[2]);

  e.Erase(2);
  e.Push_back(4);
  CHECK(4 == e[2]);

  e.Clear();
  CHECK(0 == e.Size());

  e.Resize(10);
  CHECK(10 == e.Capacity());

  CHECK_THROWS(e[100]);
  CHECK_THROWS(e[-1]);

  CHECK_THROWS(e.Resize(0));
  CHECK_THROWS(e.Resize(-1));

  CHECK_THROWS(e.Erase(-1));
}