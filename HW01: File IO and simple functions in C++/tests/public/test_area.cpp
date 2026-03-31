#include "circle.h"

#include <catch_amalgamated.hpp>

namespace {
    TEST_CASE("Area Test", "[problem 1]") {
        REQUIRE_THAT(area(radius(5, 6, -7, 11)), Catch::Matchers::WithinAbs(530.93, 0.001));
        REQUIRE_THAT(area(radius(3, 4, 0, 0)), Catch::Matchers::WithinAbs(78.539, 0.001));
    }

} // namespace
