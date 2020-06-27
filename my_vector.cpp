//
// Created by simon on 2020. 06. 27..
//
#include "my_vector.h"

Vector3D& Vector3D::operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    return (*this);
}

Vector3D& Vector3D::operator/=(float s) {
    s = 1.0F / s;
    x *= s;
    y *= s;
    z *= s;
    return (*this);
}

Vector3D& Vector3D::operator+=(const Vector3D& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return (*this);
}

Vector3D& Vector3D::operator-=(const Vector3D& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return (*this);
}

///4D:
Vector4D& Vector4D::operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return (*this);
}

Vector4D& Vector4D::operator/=(float s) {
    s = 1.0F / s;
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return (*this);
}

Vector4D& Vector4D::operator+=(const Vector4D& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return (*this);
}

Vector4D& Vector4D::operator-=(const Vector4D& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return (*this);
}
