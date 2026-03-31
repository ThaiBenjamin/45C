#include <catch_amalgamated.hpp>
#include "post_process.h"

namespace {
  TEST_CASE("29 Is Prime", "[isPrimeTest]") {
    INFO("Prime Number test is failing.");
    CHECK(isNumPrime(29));
  }

  TEST_CASE("2 Is Prime", "[isPrimeTest]") {
    INFO("Prime Number test is failing.");
    CHECK(isNumPrime(2));
  }

  TEST_CASE("1 Is Not Prime", "[isPrimeTest]") {
    INFO("Prime Number test is failing.");
    CHECK_FALSE(isNumPrime(1));
  }

  TEST_CASE("15 Is Not Prime", "[isPrimeTest]") {
    INFO("Prime Number test is failing.");
    CHECK_FALSE(isNumPrime(15));
  }

  TEST_CASE("1009 Is Not Prime", "[isPrimeTest]") {
    INFO("Prime Number test is failing.");
    CHECK(isNumPrime(1009));
  }

  TEST_CASE("100 Is Not Prime", "[isPrimeTest]") {
    INFO("Prime Number test is failing.");
    CHECK_FALSE(isNumPrime(100));
  }
}