#include "matrix.h"

#include <catch_amalgamated.hpp>

namespace {
    TEST_CASE("HW 2 Matrix Addition Test 1", "[matrixadditiontest]") {
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
        int res[AR_CAP][AR_CAP];
        int sol[AR_CAP][AR_CAP] = {
            {7,  -3, 10},
            {9,  2,  4 },
            {-8, 3,  5 }
        };

        // Act
        matrixAddition(E, n, m, F, n, m, res);

        // Assert
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                INFO("Your result and the solution to matrix addition differ at index i="
                     << i << " j=" << j);
                CHECK(res[i][j] == sol[i][j]);
            }
        }
    }

    TEST_CASE("HW 2 Matrix Addition Test 2", "[matrixadditiontest]") {
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
            {2,  4,  4 },
            {6,  9,  12},
            {14, 10, 14}
        };

        int n = 3, m = 3;
        int res[AR_CAP][AR_CAP];

        // Act
        matrixAddition(E, n, m, F, n, m, res);

        // Assert
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                INFO("Your result and the solution to matrix addition differ at index i="
                     << i << " j=" << j);
                CHECK(res[i][j] == sol[i][j]);
            }
        }
    }
} // namespace