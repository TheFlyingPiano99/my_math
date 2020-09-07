//
// Created by simon on 2020. 06. 27..
//
#include "my_vector.h"


Vector2D& Vector2D::operator*=(float s) {
    x *= s;
    y *= s;
    return (*this);
}

Vector2D& Vector2D::operator/=(float s) {
    s = 1.0F / s;
    x *= s;
    y *= s;
    return (*this);
}

Vector2D& Vector2D::operator+=(const Vector2D& v) {
    x += v.x;
    y += v.y;
    return (*this);
}

Vector2D& Vector2D::operator-=(const Vector2D& v) {
    x -= v.x;
    y -= v.y;
    return (*this);
}

float Sin(Vector2D v1, Vector2D v2) {
    return ((v1.x * v2.y - v1.y * v2.x) / (Magnitude(v1) * Magnitude(v2)));
}

float Cos(Vector2D v1, Vector2D v2) {
    return (Dot(v1, v2) / (Magnitude(v1) * Magnitude(v2)));
}

float Tan(Vector2D v1, Vector2D v2) {
    return ((v1.x * v2.y - v1.y * v2.x) / Dot(v1, v2));
}

///------------------------------------------------------------------------

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

float Sin(Vector3D v1, Vector3D v2) {
    return Magnitude(Cross(v1, v2)) / (Magnitude(v1) * Magnitude(v2));
}

float Cos(Vector3D v1, Vector3D v2) {
    return Dot(v1, v2) / (Magnitude(v1) * Magnitude(v2));
}


///----------------------------------------------------------------------------------
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



