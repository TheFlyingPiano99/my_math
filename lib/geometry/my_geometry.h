//
// Created by simon on 2020. 10. 12..
//

#ifndef MY_MATH_MY_GEOMETRY_H
#define MY_MATH_MY_GEOMETRY_H

#include "../vector/my_vector.h"


class Line3D {
    Vector3D p;
    Vector3D h;
public:
    Line3D(const Vector3D& p, const Vector3D& h):p(p), h(h) {}

};
class Plane3D {
    Vector3D p;
    Vector3D norm;
public:
    Plane3D(const Vector3D& p, const Vector3D& n): p(p), norm(n) {}
};



#endif //MY_MATH_MY_GEOMETRY_H
