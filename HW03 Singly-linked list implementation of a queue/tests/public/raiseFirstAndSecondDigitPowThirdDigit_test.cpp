#include <catch_amalgamated.hpp>
#include "gen_number.h"

namespace {
  TEST_CASE("HW 2 Raise First and Second Digit Pow Third Digit Test", "[raiseFirstAndSecondDigitPowThirdDigitTest]") {
    INFO("Raise First And Second Digit to the Power of the Third Digit if Third Digit is < 4 test is failing.");
    CHECK(raiseFirstAndSecondDigitPowThirdDigit(102) == 100);
  }
}