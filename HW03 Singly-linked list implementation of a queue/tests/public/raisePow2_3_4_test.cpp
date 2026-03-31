#include <catch_amalgamated.hpp>
#include "gen_number.h"

namespace {
  TEST_CASE("HW 2 Raise Power 234 Test", "[raisePow234Test]") {
    INFO("Raise to the power of 2 test is failing.");
    CHECK(raisePow2_3_4(12, 2) == 144);

    INFO("Raise to the power of 3 test is failing.");
    CHECK(raisePow2_3_4(12, 3) == 1728);

    INFO("Raise to the power of 4 test is failing.");
    CHECK(raisePow2_3_4(12, 4) == 20736);
  }
}