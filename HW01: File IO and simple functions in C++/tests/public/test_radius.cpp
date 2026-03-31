#include "circle.h"

#include <catch_amalgamated.hpp>

namespace {

    TEST_CASE("Radius Test", "[problem 1]") {
        REQUIRE_THAT(radius(5, 6, -7, 11), Catch::Matchers::WithinAbs(13, 0.001));
        REQUIRE_THAT(radius(3, 4, 0, 0), Catch::Matchers::WithinAbs(5, 0.001));
    }
} // namespace
