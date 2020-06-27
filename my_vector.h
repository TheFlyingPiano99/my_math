#ifndef SAJAT_TIPUSOK_H_INCLUDED
#define SAJAT_TIPUSOK_H_INCLUDED


#include <cmath>

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
};

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

inline Vector3D operator* (const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.x * b.x, a.y * b.y, a.z * b.z));
}

inline float Dot (const Vector3D& a, const Vector3D& b) {
    return (a.x*b.x + a.y*b.y + a.z*b.z);
}

inline Vector3D Cross (const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x));
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

inline Vector4D operator* (const Vector4D& a, const Vector4D& b) {
    return (Vector4D(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w));
}

inline float Dot (const Vector4D& a, const Vector4D& b) {
    return (a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w);
}

inline Vector4D Cross (const Vector4D& a, const Vector4D& b) {
    return (Vector4D(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x, 0));
}

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
