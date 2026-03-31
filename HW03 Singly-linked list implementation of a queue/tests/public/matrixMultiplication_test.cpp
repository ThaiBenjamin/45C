#include <catch_amalgamated.hpp>
#include "matrix.h"

namespace {

    TEST_CASE("HW 2 Matrix Multiplication Test", "[matrixMultiplicationTest]") {
        // Arrange
        int E[AR_CAP][AR_CAP] = {
            {2,  -1, 6},
            {1,  3,  1},
            {-4, -2, 3}
        };
        int F[AR_CAP][AR_CAP] = {
            {5,  -2, 4},
            {8,  -1, 3},
            {-4, 5,  2}
        };

        int n = 3, m = 3;
        int res[AR_CAP][AR_CAP] = { {0} };
        int sol[AR_CAP][AR_CAP] = {
            {-22, 27, 17 },
            {25,  0,  15 },
            {-48, 25, -16}
        };

        // Act
        matrixMultiplication(E, n, m, F, n, m, res);

        // Assert
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                INFO("Your result and the solution to matrix multiplication differ at index i="
                     << i << " j=" << j);
                CHECK(res[i][j] == sol[i][j]);
            }
        }
    }

    TEST_CASE("HW 2 Matrix Multiplication Test", "matrixMultiplicationTest") {
        // Arrange
        int E[AR_CAP][AR_CAP] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        int F[AR_CAP][AR_CAP] = {
            {1, 2, 1},
            {2, 4, 6},
            {7, 2, 5}
        };
        int sol[AR_CAP][AR_CAP] = {
            {26, 16, 28 },
            {56, 40, 64 },
            {86, 64, 100}
        };

        int n = 3, m = 3;
        int res[AR_CAP][AR_CAP] = { {0} };

        // Act
        matrixMultiplication(E, n, m, F, n, m, res);

        // Assert
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                INFO("Your result and the solution to matrix multiplication differ at index i="
                     << i << " j=" << j);
                CHECK(res[i][j] == sol[i][j]);
            }
        }
    }
} // namespace
