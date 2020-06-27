//
// Created by simon on 2020. 05. 25..
//

#include "my_functions.h"

///Transform:
float abs_vector (Vector4D k) {
    return std::sqrt(k.x*k.x + k.y*k.y + k.z*k.z + k.w*k.w);
}

Vector4D norm_vector(Vector4D a) {
    float abs = abs_vector(a);
    a.x = a.x / abs;
    a.y = a.y / abs;
    a.z = a.z / abs;
    a.w = a.w / abs;
    return a;
}

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
    return abs_vector(cross_product(v1, v2)) / (abs_vector(v1) * abs_vector(v2));
}

float cos (Vector4D v1, Vector4D v2) {
    return dot_product(v1, v2) / (abs_vector(v1) * abs_vector(v2));
}