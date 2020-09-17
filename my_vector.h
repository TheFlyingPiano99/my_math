#ifndef SAJAT_TIPUSOK_H_INCLUDED
#define SAJAT_TIPUSOK_H_INCLUDED


#include <cmath>
#include <iostream>

struct Vector {
private:
    float* n;
public:
    const int dimension;

    Vector(int d): dimension(d) {
        n = new float[dimension];
    }

    ~Vector() {
        delete [] n;
    }

    float& operator[] (int i) {
        return (n[i]);
    }

    const float& operator[] (int i) const {
        return (n[i]);
    }

    void fill (float val) {
        for (int i = 0; i < dimension; i++) {
            n[i] = val;
        }
    }

    Vector& operator*=(float s);
    Vector& operator/=(float s);

    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
    Vector& operator=(const Vector& v);
};


///Multiplication


inline Vector operator* (const Vector& v, float s) {
    Vector retV(v.dimension);
    for (unsigned int i = 0; i < v.dimension; i++) {
        retV[i] = v[i] * s;
    }
    return retV;
}


inline Vector operator* (float s, const Vector& v) {
    Vector retV(v.dimension);
    for (unsigned int i = 0; i < v.dimension; i++) {
        retV[i] = v[i] * s;
    }
    return retV;
}


inline float Dot (const Vector& a, const Vector& b) {
    float sum = 0;
    for (unsigned int i = 0; i < a.dimension; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}


inline Vector operator/ (const Vector& v, float s) {
    s = 1.0F / s;
    Vector retV(v.dimension);
    for (unsigned int i = 0; i < v.dimension; i++) {
        retV[i] = v[i] * s;
    }
    return retV;
}


inline Vector operator/ (const Vector& a, const Vector& b) {
    Vector retV(a.dimension);
    for (unsigned int i = 0; i < a.dimension; i++) {
        retV[i] = a[i] * (1.0F/b[i]);
    }
    return retV;
}


inline Vector operator-(const Vector& v) {
    Vector retV(v.dimension);
    for (unsigned int i = 0; i < v.dimension; i++) {
        retV[i] = -v[i];
    }
    return retV;
}


inline float Magnitude (const Vector& v) {
    float sum = 0;
    for (unsigned int i = 0; i < v.dimension; i++) {
        sum += v[i]*v[i];
    }
    return sqrtf(sum);
}


inline Vector Normalize (const Vector& v) {
    return  (v / Magnitude(v));
}

///Addition / Subtraction

inline Vector operator+ (const Vector& a, const Vector& b) {
    Vector retV(a.dimension);
    for (unsigned int i = 0; i < a.dimension; i++) {
        retV[i] = a[i] + b[i];
    }
    return retV;
}


inline Vector operator- (const Vector& a, const Vector& b) {
    Vector retV(a.dimension);
    for (unsigned int i = 0; i < a.dimension; i++) {
        retV[i] = a[i] - b[i];
    }
    return retV;
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
