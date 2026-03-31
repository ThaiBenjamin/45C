#include <catch_amalgamated.hpp>
#include "gen_number.h"

namespace {

    TEST_CASE("HW 2 Generate Num Test", "[generateNumTest]") {
        int x = generateNum();
        int y = generateNum();
        int z = generateNum();
        INFO("Random number generator is producing the same number.");
        CHECK(x >= 10); 
        CHECK(x < 100);
        CHECK(x != y); 
        CHECK(x != z);
    }
} // namespace