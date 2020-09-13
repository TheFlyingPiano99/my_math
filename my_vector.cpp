//
// Created by simon on 2020. 06. 27..
//
#include "my_vector.h"

Vector &Vector::operator*=(float s) {
    for (unsigned int i = 0; i < dimension; i++) {
        n[i] *= s;
    }
    return (*this);
}


Vector &Vector::operator/=(float s) {
    s = 1.0F / s;
    for (unsigned int i = 0; i < dimension; i++) {
        n[i] *= s;
    }
    return (*this);
}


Vector &Vector::operator+=(const Vector &v) {
    for (unsigned int i = 0; i < dimension; i++) {
        n[i] += v[i];
    }
    return (*this);
}


Vector &Vector::operator-=(const Vector &v) {
    for (unsigned int i = 0; i < dimension; i++) {
        n[i] -= v[i];
    }
    return (*this);
}

Vector &Vector::operator=(const Vector &v) {
    if (this != &v ) {
        if (this->dimension == v.dimension) {
            for (int i = 0; i < dimension; i++) {
                this->n[i] = v[i];
            }
        } else {
            throw std::runtime_error("asignment of wrong dimension.");
        }
    }
    return *this;
}

std::ostream& operator<< (std::ostream& stream, Vector& v) {
    stream <<"(";
    for (int i = 0; i < v.dimension; ++i) {
        stream << v[i];
        if (i != v.dimension-1) {
            stream << ", ";
        }
    }
    stream <<")";
    return stream;
}


///-------------------------------------------------------------------

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



