#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <queuelst/queuelst.cpp>


TEST_CASE("QueueLst ctor") {
  QueueLst st;
  Complex a{ 1.5, 2.0 };
  Complex b{ 2.0, 3.0 };
  CHECK_EQ(st.IsEmpty(), 1);
  st.Push(a);
  CHECK_EQ(st.Top(), a);
}