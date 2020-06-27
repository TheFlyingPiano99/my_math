//
// Created by simon on 2020. 05. 26..
//

#ifndef LEGITARSASAG_MATRIX_H
#define LEGITARSASAG_MATRIX_H

#include <complex>
#include <vector>

    template<typename t = std::complex<float>>
    class Matrix {
        size_t row;
        size_t column;
        std::vector<std::vector<t>> mx;
    public:
        Matrix(size_t r, size_t c) : row(r), column(c) {
            mx.resize(row);
            for (size_t i = 0; i < row; i++) {
                mx[i].resize(column);
            }
        }

        std::vector<t> &operator[](int r) {
            return mx[r];
        }

        const std::vector<t> &operator[](int r) const{
            return mx[r];
        }

        void clear();

        void fill(t val);

        int getRowN() const{
            return row;
        }

        int getColumnN() const{
            return column;
        }

        Matrix<t> operator*(Matrix<t> &mx2);
    };

    std::ostream& operator<<(std::ostream&, const Matrix<float>&);


#include "my_vector.h"

class Matrix3D {
    float n[3][3]; //column-major - Oszlopfolytonos tarolas.
public:
    Matrix3D() = default;
    Matrix3D(float n00, float n01,float n02,
             float n10, float n11,float n12,
             float n20, float n21,float n22) {
        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
    }

    Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c) {
        n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
        n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
        n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
    }

    float& operator() (int r, int c) {
        return (n[c][r]);
    }

    const float& operator() (int r, int c) const {
        return (n[c][r]);
    }

    Vector3D& operator[] (int c) {
        return (*reinterpret_cast<Vector3D*>(n[c]));
    }

    const Vector3D& operator[] (int c) const {
        return (*reinterpret_cast<const Vector3D*>(n[c]));
    }

};

///Multiplication
Matrix3D operator*(const Matrix3D& A, const Matrix3D& B);
Vector3D operator*(const Matrix3D& M, const Vector3D& v);
inline Matrix3D operator*(float s, const Matrix3D& M);

inline Matrix3D Transpose(const Matrix3D& M);

///Addition / Subtraction
inline Matrix3D operator+(const Matrix3D& A, const Matrix3D& B);
inline Matrix3D operator-(const Matrix3D& A, const Matrix3D& B);

///4D:
class Matrix4D {
    float n[3][3]; //column-major - Oszlopfolytonos tarolas.
public:
    Matrix4D() = default;
    Matrix4D(float n00, float n01,float n02, float n03,
             float n10, float n11,float n12, float n13,
             float n20, float n21,float n22, float n23,
             float n30, float n31,float n32, float n33) {
        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; n[0][3] = n30;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; n[1][3] = n31;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; n[2][3] = n32;
        n[3][0] = n03; n[3][1] = n13; n[3][2] = n23; n[3][3] = n33;
    }

    Matrix4D(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d) {
        n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z; n[0][3] = a.w;
        n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z; n[1][3] = b.w;
        n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z; n[2][3] = c.w;
        n[3][0] = d.x; n[3][1] = d.y; n[3][2] = d.z; n[3][3] = d.w;
    }

    float& operator() (int r, int c) {
        return (n[c][r]);
    }

    const float& operator() (int r, int c) const {
        return (n[c][r]);
    }

    Vector4D& operator[] (int c) {
        return (*reinterpret_cast<Vector4D*>(n[c]));
    }

    const Vector4D& operator[] (int c) const {
        return (*reinterpret_cast<const Vector4D*>(n[c]));
    }

};

///Multiplication
Matrix4D operator*(const Matrix4D& A, const Matrix4D& B);
Vector4D operator*(const Matrix4D& M, const Vector4D& v);
inline Matrix4D operator*(float s, const Matrix4D& M);

inline Matrix4D Transpose(const Matrix4D& M);

///Addition / Subtraction
inline Matrix4D operator+(const Matrix4D& A, const Matrix4D& B);
inline Matrix4D operator-(const Matrix4D& A, const Matrix4D& B);

#endif //LEGITARSASAG_MATRIX_H
