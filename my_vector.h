#ifndef SAJAT_TIPUSOK_H_INCLUDED
#define SAJAT_TIPUSOK_H_INCLUDED


#include <cmath>
#include <iostream>

template <unsigned int dimension>
struct Vector {
    float n[dimension];
public:
    Vector<dimension>() = default;

    float& operator[] (int i) {
        return (n[i]);
    }

    const float& operator[] (int i) const {
        return (n[i]);
    }

    Vector<dimension>& operator*=(float s);
    Vector<dimension>& operator/=(float s);

    Vector<dimension>& operator+=(const Vector<dimension>& v);
    Vector<dimension>& operator-=(const Vector<dimension>& v);
};

template<unsigned int dimension>
Vector<dimension> &Vector<dimension>::operator*=(float s) {
    for (unsigned int i = 0; i < dimension; i++) {
        n[i] *= s;
    }
    return (*this);
}

template<unsigned int dimension>
Vector<dimension> &Vector<dimension>::operator/=(float s) {
    s = 1.0F / s;
    for (unsigned int i = 0; i < dimension; i++) {
        n[i] *= s;
    }
    return (*this);
}

template<unsigned int dimension>
Vector<dimension> &Vector<dimension>::operator+=(const Vector<dimension> &v) {
    for (unsigned int i = 0; i < dimension; i++) {
        n[i] += v[i];
    }
    return (*this);
}

template<unsigned int dimension>
Vector<dimension> &Vector<dimension>::operator-=(const Vector<dimension> &v) {
    for (unsigned int i = 0; i < dimension; i++) {
        n[i] -= v[i];
    }
    return (*this);
}

///Multiplication

template<unsigned int dimension>
inline Vector<dimension> operator* (const Vector<dimension>& v, float s) {
    Vector<dimension> retV;
    for (unsigned int i = 0; i < dimension; i++) {
        retV[i] = v[i] * s;
    }
    return retV;
}

template<unsigned int dimension>
inline Vector<dimension> operator* (float s, const Vector<dimension>& v) {
    Vector<dimension> retV;
    for (unsigned int i = 0; i < dimension; i++) {
        retV[i] = v[i] * s;
    }
    return retV;
}

template<unsigned int dimension>
inline float Dot (const Vector<dimension>& a, const Vector<dimension>& b) {
    float sum = 0;
    for (unsigned int i = 0; i < dimension; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

template<unsigned int dimension>
inline Vector<dimension> operator/ (const Vector<dimension>& v, float s) {
    s = 1.0F / s;
    Vector<dimension> retV;
    for (unsigned int i = 0; i < dimension; i++) {
        retV[i] = v[i] * s;
    }
    return retV;
}

template<unsigned int dimension>
inline Vector<dimension> operator/ (const Vector<dimension>& a, const Vector<dimension>& b) {
    Vector<dimension> retV;
    for (unsigned int i = 0; i < dimension; i++) {
        retV[i] = a[i] * (1.0F/b[i]);
    }
    return retV;
}

template<unsigned int dimension>
inline Vector<dimension> operator-(const Vector<dimension>& v) {
    Vector<dimension> retV;
    for (unsigned int i = 0; i < dimension; i++) {
        retV[i] = -v[i];
    }
    return retV;
}

template<unsigned int dimension>
inline float Magnitude (const Vector<dimension>& v) {
    float sum = 0;
    for (unsigned int i = 0; i < dimension; i++) {
        sum += v[i]*v[i];
    }
    return sqrtf(sum);
}

template<unsigned int dimension>
inline Vector<dimension> Normalize (const Vector<dimension>& v) {
    return  (v / Magnitude(v));
}

///Addition / Subtraction
template<unsigned int dimension>
inline Vector<dimension> operator+ (const Vector<dimension>& a, const Vector<dimension>& b) {
    Vector<dimension> retV;
    for (unsigned int i = 0; i < dimension; i++) {
        retV[i] = a[i] + b[i];
    }
    return retV;
}

template<unsigned int dimension>
inline Vector<dimension> operator- (const Vector<dimension>& a, const Vector<dimension>& b) {
    Vector<dimension> retV;
    for (unsigned int i = 0; i < dimension; i++) {
        retV[i] = a[i] - b[i];
    }
    return retV;
}

template<unsigned int dimension>
std::ostream& operator<< (std::ostream& stream, Vector<dimension>& v) {
    stream <<"(";
    for (int i = 0; i < dimension; ++i) {
        stream << v[i];
        if (i != dimension-1) {
            stream << ", ";
        }
    }
    stream <<")";
    return stream;
}

///-------------------------------------------------------------------------------

struct Vector1D {
    float x;
    Vector1D() = default;
    Vector1D(float x): x(x) {}

    float& operator[] (int i) {
        return ((&x)[i]);
    }

    const float& operator[] (int i) const {
        return ((&x)[i]);
    }
};

struct Vector2D {
    float x;
    float y;

    Vector2D() = default;
    Vector2D(float x, float y): x(x), y(y) {}

    float& operator[] (int i) {
        return ((&x)[i]);
    }

    const float& operator[] (int i) const {
        return ((&x)[i]);
    }

    Vector2D& operator*=(float s);
    Vector2D& operator/=(float s);

    Vector2D& operator+=(const Vector2D& v);
    Vector2D& operator-=(const Vector2D& v);
};

inline Vector2D operator* (const Vector2D& v, float s) {
    return (Vector2D(v.x * s, v.y * s));
}
inline Vector2D operator* (float s, const Vector2D& v) {
    return (Vector2D(v.x * s, v.y * s));
}

inline float Dot (const Vector2D& a, const Vector2D& b) {
    return (a.x*b.x + a.y*b.y);
}

///Cross() undefined!
inline Vector2D Orthogonal (const Vector2D& v) {
    return {v.y, -v.x};
}

inline Vector2D operator/ (const Vector2D& v, float s) {
    s = 1.0F / s;
    return (Vector2D(v.x * s, v.y * s));
}

inline Vector2D operator/ (const Vector2D& a, const Vector2D& b) {
    return (Vector2D(a.x * (1.0F/b.x), a.y * (1.0F/b.y)));
}

inline Vector2D operator-(const Vector2D& v) {
    return (Vector2D(-v.x, -v.y));
}

inline float Magnitude (const Vector2D& v) {
    return (sqrtf(v.x*v.x + v.y*v.y));
}

inline Vector2D Normalize (const Vector2D& v) {
    return  (v / Magnitude(v));
}

///Addition / Subtraction
inline Vector2D operator+ (const Vector2D& a, const Vector2D& b) {
    return (Vector2D(a.x+b.x, a.y+b.y));
}

inline Vector2D operator- (const Vector2D& a, const Vector2D& b) {
    return (Vector2D(a.x-b.x, a.y-b.y));
}


///Trigonometry:
float Sin (Vector2D v1, Vector2D v2);


float Cos (Vector2D v1, Vector2D v2);

float Tan (Vector2D v1, Vector2D v2);

///------------------------------------------------------

struct Vector3D {
    float x;
    float y;
    float z;

    Vector3D() = default;
    Vector3D(float x, float y, float z): x(x), y(y), z(z) {}

    float& operator[] (int i) {
        return ((&x)[i]);
    }

    const float& operator[] (int i) const {
        return ((&x)[i]);
    }

    Vector3D& operator*=(float s);
    Vector3D& operator/=(float s);

    Vector3D& operator+=(const Vector3D& v);
    Vector3D& operator-=(const Vector3D& v);

    };

///Multiplication

inline Vector3D operator* (const Vector3D& v, float s) {
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}
inline Vector3D operator* (float s, const Vector3D& v) {
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline float Dot (const Vector3D& a, const Vector3D& b) {
    return (a.x*b.x + a.y*b.y + a.z*b.z);
}

inline Vector3D Cross (const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.y*b.z - a.z*b.y,
                     a.z*b.x - a.x*b.z,
                     a.x*b.y - a.y*b.x));
}

inline Vector3D operator/ (const Vector3D& v, float s) {
    s = 1.0F / s;
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator/ (const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.x * (1.0F/b.x), a.y * (1.0F/b.y), a.z * (1.0F/b.z)));
}

inline Vector3D operator-(const Vector3D& v) {
    return (Vector3D(-v.x, -v.y, -v.z));
}

inline float Magnitude (const Vector3D& v) {
    return (sqrtf(v.x*v.x + v.y*v.y + v.z*v.z));
}

inline Vector3D Normalize (const Vector3D& v) {
    return  (v / Magnitude(v));
}

///Addition / Subtraction
inline Vector3D operator+ (const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.x+b.x, a.y+b.y, a.z+b.z));
}

inline Vector3D operator- (const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.x-b.x, a.y-b.y, a.z-b.z));
}


///Trigonometry:
float Sin (Vector3D v1, Vector3D v2);

float Cos (Vector3D v1, Vector3D v2);

///Project/Reject:
inline Vector3D Project (const Vector3D& a, const Vector3D& b) {
    return Vector3D(b * (Dot(a, b) / Dot(b, b)));
}

inline Vector3D Reject (const Vector3D& a, const Vector3D& b) {
    return Vector3D(a - b * (Dot(a, b) / Dot(b, b)));
}

///------------------------------------------------
struct Vector4D {
    float x;
    float y;
    float z;
    float w;

    Vector4D() = default;
    Vector4D(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {}

    float& operator[] (int i) {
        return ((&x)[i]);
    }

    const float& operator[] (int i) const {
        return ((&x)[i]);
    }

    Vector4D& operator*=(float s);
    Vector4D& operator/=(float s);

    Vector4D& operator+=(const Vector4D& v);
    Vector4D& operator-=(const Vector4D& v);

};

///Multiplication

inline Vector4D operator* (const Vector4D& v, float s) {
    return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
}
inline Vector4D operator* (float s, const Vector4D& v) {
    return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
}

inline float Dot (const Vector4D& a, const Vector4D& b) {
    return (a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w);
}

///Cross() undefined!

inline Vector4D operator/ (const Vector4D& v, float s) {
    s = 1.0F / s;
    return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
}

inline Vector4D operator/ (const Vector4D& a, const Vector4D& b) {
    return (Vector4D(a.x * (1.0F/b.x), a.y * (1.0F/b.y), a.z * (1.0F/b.z), a.w * (1.0F/b.w)));
}

inline Vector4D operator-(const Vector4D& v) {
    return (Vector4D(-v.x, -v.y, -v.z, -v.w));
}

inline float Magnitude (const Vector4D& v) {
    return (sqrtf(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w));
}

inline Vector4D Normalize (const Vector4D& v) {
    return  (v / Magnitude(v));
}

///Addition / Subtraction
inline Vector4D operator+ (const Vector4D& a, const Vector4D& b) {
    return (Vector4D(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w));
}

inline Vector4D operator- (const Vector4D& a, const Vector4D& b) {
    return (Vector4D(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w));
}



#endif // SAJAT_TIPUSOK_H_INCLUDED
