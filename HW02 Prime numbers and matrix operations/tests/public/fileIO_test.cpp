#include "matrix.h"

#include <catch_amalgamated.hpp>

namespace {
    TEST_CASE("HW 2 File IO Test", "[fileiotest]") {
        // Arrange
        int A[AR_CAP][AR_CAP] = {};
        int B[AR_CAP][AR_CAP] = {};
        int n1, m1, n2, m2;

        // Act
        fileIO("input.txt", A, n1, m1, B, n2, m2);
        int A_fi[AR_CAP][AR_CAP] = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };
        int B_fi[AR_CAP][AR_CAP] = {
            {1, 2, 3},
            {3, 3, 0},
            {0, 1, 3}
        };

        // Assert
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m1; ++j) {
                INFO("Matrix A and A_fi differ at index i=" << i << " and j=" << j);
                CHECK(A[i][j] == A_fi[i][j]);

                INFO("Matrix B and B_fi differ at index i=" << i << " and j=" << j);
                CHECK(B[i][j] == B_fi[i][j]);
            }
        }
    }

} // namespace