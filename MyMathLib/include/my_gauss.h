//
// Created by simon on 2020. 09. 13..
//

#ifndef MY_MATH_MY_GAUSS_H
#define MY_MATH_MY_GAUSS_H

#include "my_matrix.h"

class Vector;

class Gauss {

public:

    class GaussException: public std::exception {
    };

    class NoSolution: public GaussException {
    public:
        const char * what() const noexcept override {
            return "No solution of the matrix.";
        }
    };

    class InfiniteSolutions: public GaussException {
    public:
        const char * what() const noexcept override {
            return "Infinite solutions of the matrix.";
        }
    };

    enum SingularityFlag {
        noSolution,
        cleanSolution,
        infiniteSolutions
    };

    /**
     * Gauss elimination for column major matrix.
     * @param M - (N+1)*N matrix The right side values should be in the last row.
     * Will be modified!!!
     * @return Vector - The solution of the linear system. The 0. index value of the vector is the value of the
     * 0. index variable.
     * @throws GaussException - if the matrix has no solution or has infinite solutions.
     */
    static Vector Eliminate (Matrix& M);

    /**
 * function to reduce matrix to r.e.f.
 * @param M - Matrix to reduce. Will be modified!
 * @return SingularityFlag: {
 *                              noSolution,
 *                              cleanSolution,
 *                              infiniteSolutions
 *                          }
 */
    static SingularityFlag Reduce(Matrix& M);


    //Auxiliary functions:

    /**
     * Swaps content of two columns of M matrix.
     * @param M - Column major matrix
     * @param col1 - Column no. 1
     * @param col2 - Column no. 2
     */
    static void SwapColumn (Matrix& M, int col1, int col2);
};

Matrix CoefficientMatrix (const Matrix& M, const Vector& v);

#endif //MY_MATH_MY_GAUSS_H
