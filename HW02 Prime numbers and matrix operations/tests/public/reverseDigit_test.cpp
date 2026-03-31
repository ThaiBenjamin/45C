#include <catch_amalgamated.hpp>
#include "gen_number.h"

namespace {
  TEST_CASE("HW 2 Reverse Digit Test 1", "[reverseDigitTest]") {
    INFO("Reverse digit 24 did not equal 42.");
    CHECK(reverseDigit(24) == 42);

    INFO("Reverse digit 97 did not equal 79.");
    CHECK(reverseDigit(97) == 79);
  }
}
