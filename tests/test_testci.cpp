#include "doctest.h"
#include "test.hpp"

TEST_CASE("test case 1") { CHECK(testci() == 1); }

TEST_CASE("test case 2") { 
  auto result = testci();
  CHECK(result == 1); 
}
