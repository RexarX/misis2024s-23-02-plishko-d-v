#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <dynarr/dynarr.cpp>

TEST_CASE("DynamicArray ctor") {
  DynArr<int> q;
  DynArr<int> w;

  CHECK_EQ(q[0], 0);

  q.Push_back(10);
  w = q;
  CHECK_EQ(w, q);

  CHECK_EQ(10, q[0]);
  CHECK_EQ(10, w[0]);

  w.Push_back(1);
  CHECK(w != q);
}

TEST_CASE("DynamicArray methods") {
  DynArr<int> e;
  
  CHECK_THROWS(e.Pop_back());
  
  e.Push_back(10);
  e.Push_back(1);
  e.Push_back(2);
  e.Push_back(3);
  CHECK_EQ(10, e[0]);
  CHECK_EQ(1, e[1]);
  CHECK_EQ(2, e[2]);
  CHECK_EQ(3, e[3]);

  e.Pop_back();
  CHECK_EQ(2, e[2]);

  e.Erase(2);
  e.Push_back(4);
  CHECK_EQ(4, e[2]);

  e.Clear();
  CHECK_EQ(0, e.Size());

  e.Resize(10);
  CHECK_EQ(10, e.Size());

  for (ptrdiff_t i = 0; i < e.Size(); i++) {
    CHECK_EQ(e[i], 0);
  }

  e.Resize(2);
  CHECK_EQ(2, e.Size());

  for (ptrdiff_t i = 0; i < e.Size(); i++) {
    CHECK_EQ(e[i], 0);
  }

  CHECK_THROWS(e[100]);
  CHECK_THROWS(e[-1]);

  CHECK_THROWS(e.Resize(0));
  CHECK_THROWS(e.Resize(-1));

  CHECK_THROWS(e.Erase(-1));
}