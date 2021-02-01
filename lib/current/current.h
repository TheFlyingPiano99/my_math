//
// Created by simon on 2020. 10. 15..
//

#ifndef MY_MATH_CURRENT_H
#define MY_MATH_CURRENT_H

#include "matrix/my_matrix.h"
#include "vector/my_vector.h"
#include "graph/my_graph.h"

class Circuit {
public:
    static Vector calculateCurrentOnLinear (const Graph& g, const Vector& r, const Vector& u0);
    static Matrix buildSystem (const Graph& g, const Matrix& incidence, const Matrix& cycle, const Vector& U0);
};

#endif //MY_MATH_CURRENT_H
