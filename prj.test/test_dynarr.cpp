#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <dynarr/dynarr.cpp>
#include <string>

TEST_CASE("DynamicArray ctor") {
  DynArr<int> q;
  q[0] = 10;
  CHECK(10 == q[0]);

  CHECK_THROWS(q[-1]);
}