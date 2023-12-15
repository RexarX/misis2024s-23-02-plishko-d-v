#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <dynarr/dynarr.cpp>

TEST_CASE("DynamicArray ctor") {
  DynArr q;
  DynArr w;

  CHECK_EQ(q[0], 0.0f);

  q.Push_back(10.0f);

  w = q;
  CHECK_EQ(w, q);

  CHECK_EQ(10.0f, q[0]);
  CHECK_EQ(10.0f, w[0]);

  w.Push_back(1.0f);
  CHECK(w != q);

  q.Clear();

  CHECK_EQ(q[0], 0.0f);

  q.Push_back(10.0f);

  DynArr e(q);

  CHECK_EQ(q, e);

  CHECK_EQ(10.0f, q[0]);
  CHECK_EQ(10.0f, e[0]);

  e.Push_back(1.0f);
  CHECK(e != q);
}

TEST_CASE("DynamicArray methods") {
  DynArr e;
  CHECK_THROWS(e.Pop_back());
  
  e.Push_back(10.0f);
  e.Push_back(1.0f);
  e.Push_back(2.0f);
  e.Push_back(3.0f);
  CHECK_EQ(10.0f, e[0]);
  CHECK_EQ(1.0f, e[1]);
  CHECK_EQ(2.0f, e[2]);
  CHECK_EQ(3.0f, e[3]);

  e.Pop_back();
  CHECK_EQ(2.0f, e[2]);

  e.Erase(2);
  e.Push_back(4.0f);
  CHECK_EQ(4.0f, e[2]);

  e.Clear();
  CHECK_EQ(0.0f, e.Size());

  e.Resize(10);
  CHECK_EQ(10, e.Size());

  for (ptrdiff_t i = 0; i < e.Size(); i++) {
    CHECK_EQ(e[i], 0.0f);
  }

  e.Resize(2);
  CHECK_EQ(2, e.Size());

  for (ptrdiff_t i = 0; i < e.Size(); i++) {
    CHECK_EQ(e[i], 0.0f);
  }

  CHECK_THROWS(e[100]);
  CHECK_THROWS(e[-1]);

  CHECK_THROWS(e.Resize(0));
  CHECK_THROWS(e.Resize(-1));

  CHECK_THROWS(e.Erase(-1));
}