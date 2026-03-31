#include "matrix.h"

#include <catch_amalgamated.hpp>

namespace {

    TEST_CASE("HW 2 Matrix Determinant Test 1", "[matrixDeterminantTest]") {
        // Arrange
        int E[3][3] = {
            {1, 3,  -2},
            {0, 5,  1 },
            {4, -1, 2 }
        };

        int res;
        int sol = 63;

        // Act
        res = matrixDeterminant3D(E);

        // Assert
        INFO("3D matrix determinant failed");
        CHECK(res == sol);
    }

    TEST_CASE("HW 2 Matrix Determinant Test 2", "[matrixDeterminantTest]") {
        // Arrange
        int E[3][3] = {
            {1,  3,  2 },
            {-3, -1, -3},
            {2,  3,  1 }
        };

        int res;
        int sol = -15;

        // Act
        res = matrixDeterminant3D(E);

        // Assert
        INFO("3D matrix determinant failed");
        CHECK(res == sol);
    }
} // namespace