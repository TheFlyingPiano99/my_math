//
// Created by simon on 2020. 10. 15..
//

#ifndef MY_MATH_CURRENT_H
#define MY_MATH_CURRENT_H

#include "my_matrix.h"
#include "my_vector.h"
#include "my_graph.h"

class Circuit {
public:
    static Vector calculateCurrentOnLinear (const Graph& g, const Vector& r, const Vector& u0);
};

#endif //MY_MATH_CURRENT_H
