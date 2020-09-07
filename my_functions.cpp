//
// Created by simon on 2020. 05. 25..
//

#include "my_functions.h"

///Multiplication:
float dot_product(Vector4D a, Vector4D b) {
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

Vector4D cross_product(Vector4D a, Vector4D b) {
    Vector4D res;
    res.x = a.y * b.z - a.z * b.y,
    res.y = a.z * b.x - a.x * b.z,
    res.z = a.x * b.y - a.y * b.x;
    res.w = 0;
    return res;
}

