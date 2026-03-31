#include <catch_amalgamated.hpp>
#include "gen_number.h"

namespace {
  TEST_CASE("HW 2 Sum Digits Test 1", "[sumDigitsTest]") {
    INFO("Sum of Digits test is failing.");
    CHECK(sumDigits(56) == 11);

    INFO("Sum of Digits test is failing.");
    CHECK(sumDigits(34) == 7);
  }
}

