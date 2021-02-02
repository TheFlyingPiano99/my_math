//
// Created by simon on 2021. 02. 02..
//


#include "gtest/gtest.h"
#include "../../MyMathLib/include/my_matrix.h"

TEST(matrix_test, test_eq) {
    Matrix2D m = Matrix2D(0,0,0,0);
    EXPECT_NO_THROW(m[0]);
}