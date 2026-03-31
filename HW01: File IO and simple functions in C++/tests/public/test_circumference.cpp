#include "circle.h"
#include <catch_amalgamated.hpp>

namespace {
    TEST_CASE("Circumference Test", "[problem 1]") {
        REQUIRE_THAT(circumference(radius(5, 6, -7, 11)),
                     Catch::Matchers::WithinAbs(81.6816, 0.001));
        REQUIRE_THAT(circumference(radius(3, 4, 0, 0)),
                     Catch::Matchers::WithinAbs(31.4161, 0.001));
    }
} // namespace
