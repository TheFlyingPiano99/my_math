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

///Trigonometry:
float sin (Vector4D v1, Vector4D v2) {
    return Magnitude(cross_product(v1, v2)) / (Magnitude(v1) * Magnitude(v2));
}

float cos (Vector4D v1, Vector4D v2) {
    return dot_product(v1, v2) / (Magnitude(v1) * Magnitude(v2));
}