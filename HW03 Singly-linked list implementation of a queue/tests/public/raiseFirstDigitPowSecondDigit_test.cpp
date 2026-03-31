#include <catch_amalgamated.hpp>
#include "gen_number.h"

namespace {
  TEST_CASE("HW 2 Raise FIrst Digit Pow Second Digit Test 1", "[raiseFirstDigitPowSecondDigitTest]") {
    INFO("Raise the First Digit to the Power of the Second Digit Test is failing.");
    CHECK(raiseFirstDigitPowSecondDigit(42) == 16);
  }
}