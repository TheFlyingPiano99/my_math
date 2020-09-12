//
// Created by simon on 2020. 05. 26..
//

#ifndef LEGITARSASAG_MATRIX_H
#define LEGITARSASAG_MATRIX_H

#include <complex>
#include <vector>

#include "my_vector.h"

/**
 * Float matrix, with column-major order (template size)
 * @tparam r - number of row
 * @tparam c - number of columns
 */
template<unsigned int row, unsigned int column>
class Matrix {
    float n[column][row];
public:
    Matrix<row, column>() = default;

    float& operator() (int r, int c) { //indexeles (sor, oszlop)
        return (n[c][r]);
    }

    const float& operator() (int r, int c) const { //indexeles (sor, oszlop)
        return (n[c][r]);
    }

    Vector<row>& operator[] (int c) { //indexeles oszlopvektorral visszaterve (sor)
        return (*reinterpret_cast<Vector<row>*>(n[c]));
    }

    const Vector<row>& operator[] (int c) const { //indexeles oszlopvektorral visszaterve (sor)
        return (*reinterpret_cast<Vector<row>*>(n[c]));
    }

    void fill(float val) {
        for (unsigned int c = 0; c < column; c++) {
            for (unsigned int r = 0; r < row; r++) {
                n[c][r] = val;
            }
        }
    }
};

///Multiplication
template<unsigned int row1, unsigned int column1row2, unsigned int column2>
inline Matrix<row1, column2> operator*(const Matrix<row1, column1row2> &A, const Matrix<column1row2, column2> &B) {
    Matrix<row1, column2> retM;
    for (unsigned int c = 0; c < column2; c++) {
        for (unsigned int r = 0; r < row1; r++) {
            float n = 0;
            for (unsigned int k = 0; k < column1row2; k++) {
                n += A(r, k) * B(k, c);
            }
            retM(r, c) = n;
        }
    }
    return retM;
}

template<unsigned int row, unsigned int column>
inline Vector<row> operator*(const Matrix<row, column> &M, const Vector<column> &v) {
    Vector<row> retV;
    for (unsigned int r = 0; r < row; r++) {
        float n = 0;
        for (unsigned int k = 0; k < column; k++) {
            n += M(r, k) * v[k];
        }
        retV[r] = n;
    }
    return retV;
}

template<unsigned int row, unsigned int column>
inline Matrix<row, column> operator*(float s, const Matrix<row, column> &M) {
    Matrix<row, column> retM;
    for (unsigned int c = 0; c < column; c++) {
        for (unsigned int r = 0; r < row; r++) {
            retM(r, c) = M(r, c) * s;
        }
    }
    return retM;
}
template<unsigned int row, unsigned int column>
inline Matrix<row, column> operator*(const Matrix<row, column> &M, float s) {
    Matrix<row, column> retM;
    for (unsigned int c = 0; c < column; c++) {
        for (unsigned int r = 0; r < row; r++) {
            retM(r, c) = M(r, c) * s;
        }
    }
    return retM;
}

template<unsigned int row, unsigned int column>
inline Matrix<column, row> Transpose(const Matrix<row, column>& M) {
    Matrix<column, row> retM;
    for (unsigned int c = 0; c < column; c++) {
        for (unsigned int r = 0; r < row; r++) {
            retM(c, r) = M(r, c);
        }
    }
    return retM;
}

///Addition / Subtraction
template<unsigned int row, unsigned int column>
inline Matrix<row, column> operator+(const Matrix<row, column>& A, const Matrix<row, column>& B) {
    Matrix<row, column> retM;
    for (unsigned int c = 0; c < column; c++) {
        for (unsigned int r = 0; r < column; r++) {
            retM(r, c) = A(r, c) + B(r, c);
        }
    }
    return retM;
}

template<unsigned int row, unsigned int column>
inline Matrix<row, column> operator-(const Matrix<row, column>& A, const Matrix<row, column>& B) {
    Matrix<row, column> retM;
    for (unsigned int c = 0; c < column; c++) {
        for (unsigned int r = 0; r < column; r++) {
            retM(r, c) = A(r, c) - B(r, c);
        }
    }
    return retM;
}

template<unsigned int row, unsigned int column>
inline std::ostream &operator<<(std::ostream &stream, const Matrix<row, column> &M) {
    for (unsigned int r = 0; r < row; r++) {
        stream << "|";
        for (unsigned int c = 0; c < column; c++) {
            stream << M(r, c) << "|";
        }
        stream << "\n";
    }
    return stream;
}

class Matrix2D {
    float n[2][2];
public:
    Matrix2D() = default;

    Matrix2D(float n00, float n01,
             float n10, float n11) {
        n[0][0] = n00; n[0][1] = n10;
        n[1][0] = n01; n[1][1] = n11;
    }

    Matrix2D(const Vector2D& a, const Vector2D& b) {
        n[0][0] = a.x; n[0][1] = a.y;
        n[1][0] = b.x; n[1][1] = b.y;
    }

    float& operator() (int r, int c) { //indexeles (sor, oszlop)
        return (n[c][r]);
    }

    const float& operator() (int r, int c) const { //indexeles (sor, oszlop)
        return (n[c][r]);
    }

    Vector2D& operator[] (int c) { //indexeles oszlopvektorral visszaterve (sor)
        return (*reinterpret_cast<Vector2D*>(n[c]));
    }

    const Vector2D& operator[] (int c) const { //indexeles oszlopvektorral visszaterve (sor)
        return (*reinterpret_cast<const Vector2D*>(n[c]));
    }

};

///Multiplication
Matrix2D operator*(const Matrix2D& A, const Matrix2D& B); ///Last tested.
Vector2D operator*(const Matrix2D& M, const Vector2D& v);
Matrix2D operator*(float s, const Matrix2D& M);
Matrix2D operator*(const Matrix2D& M, float s);

Matrix2D Transpose(const Matrix2D& M);

///Addition / Subtraction
Matrix2D operator+(const Matrix2D& A, const Matrix2D& B);
Matrix2D operator-(const Matrix2D& A, const Matrix2D& B);

float Determinant (const Matrix2D& M);


///-------------------------------------------------------------------
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

    float& operator() (int r, int c) { //indexeles (sor, oszlop)
        return (n[c][r]);
    }

    const float& operator() (int r, int c) const { //indexeles (sor, oszlop)
        return (n[c][r]);
    }

    Vector3D& operator[] (int c) { //indexeles oszlopvektorral visszaterve (sor)
        return (*reinterpret_cast<Vector3D*>(n[c]));
    }

    const Vector3D& operator[] (int c) const { //indexeles oszlopvektorral visszaterve (sor)
        return (*reinterpret_cast<const Vector3D*>(n[c]));
    }

};

///Multiplication
Matrix3D operator*(const Matrix3D& A, const Matrix3D& B); ///Last tested.
Vector3D operator*(const Matrix3D& M, const Vector3D& v);
Matrix3D operator*(float s, const Matrix3D& M);
Matrix3D operator*(const Matrix3D& M, float s);

Matrix3D Transpose(const Matrix3D& M);

///Addition / Subtraction
Matrix3D operator+(const Matrix3D& A, const Matrix3D& B);
Matrix3D operator-(const Matrix3D& A, const Matrix3D& B);

float Determinant (const Matrix3D& M);



///-----------------------------------------------------------------------------------
///4D:
class Matrix4D {
    float n[4][4]; //column-major - Oszlopfolytonos tarolas.
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

    float& operator() (int r, int c) { //indexeles (sor, oszlop)
        return (n[c][r]);
    }

    const float& operator() (int r, int c) const { //indexeles (sor, oszlop)
        return (n[c][r]);
    }

    Vector4D& operator[] (int c) { //indexeles oszlopvektorral visszaterve (sor)
        return (*reinterpret_cast<Vector4D*>(n[c]));
    }

    const Vector4D& operator[] (int c) const { //indexeles oszlopvektorral visszaterve (sor)
        return (*reinterpret_cast<const Vector4D*>(n[c]));
    }

};

///Multiplication
Matrix4D operator*(const Matrix4D& A, const Matrix4D& B);
Vector4D operator*(const Matrix4D& M, const Vector4D& v);
Matrix4D operator*(float s, const Matrix4D& M);
Matrix4D operator*(const Matrix4D& M, float s);

Matrix4D Transpose(const Matrix4D& M);

///Addition / Subtraction
Matrix4D operator+(const Matrix4D& A, const Matrix4D& B);
Matrix4D operator-(const Matrix4D& A, const Matrix4D& B);

float Determinant (const Matrix4D& M);


#endif //LEGITARSASAG_MATRIX_H
