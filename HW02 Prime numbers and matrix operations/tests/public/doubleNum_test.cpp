#include "gen_number.h"

#include <catch_amalgamated.hpp>

namespace {

    TEST_CASE("HW 2 Double Num Test 1", "[doubleNumTest]") {
        INFO("Double Number test is failing.");
        CHECK(doubleNum(45) == 90);
    }
} // namespace