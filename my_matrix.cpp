//
// Created by simon on 2020. 05. 26..
//

#include <stdexcept>
#include "my_matrix.h"



///Global:

///------------------------------------------------------------------------------------------------
///2D:
Matrix2D operator*(const Matrix2D &A, const Matrix2D &B) {
    return(Matrix2D(
            A(0,0) * B(0,0) + A(0,1) * B(1,0),
            A(0,0) * B(0,1) + A(0,1) * B(1,1),

            A(1,0) * B(0,0) + A(1,1) * B(1,0),
            A(1,0) * B(0,1) + A(1,1) * B(1,1)
    ));
}

Vector2D operator*(const Matrix2D &M, const Vector2D &v) {
    return (Vector2D(M(0,0) * v.x + M(0,1) * v.y,
                     M(1,0) * v.x + M(1,1) * v.y
    ));
}

Matrix2D operator*(float s, const Matrix2D &M) {
    return (Matrix2D(s * M(0,0), s * M(0,1),
                     s * M(1,0), s * M(1,1)
    ));
}

Matrix2D operator*(const Matrix2D &M, float s) {
    return (Matrix2D(s * M(0,0), s * M(0,1),
                     s * M(1,0), s * M(1,1)
    ));
}

Matrix2D Transpose(const Matrix2D &M) {
    return (Matrix2D(M(0,0), M(1,0),
                     M(0,1), M(1,1)
    ));
}

Matrix2D operator+(const Matrix2D &A, const Matrix2D &B) {
    return (Matrix2D(A(0,0) + B(0,0), A(0,1) + B(0,1),
                     A(1,0) + B(1,0), A(1,1) + B(1,1)
    ));
}

Matrix2D operator-(const Matrix2D &A, const Matrix2D &B) {
    return (Matrix2D(A(0,0) - B(0,0), A(0,1) - B(0,1),
                     A(1,0) - B(1,0), A(1,1) - B(1,1)
    ));
}

float Determinant(const Matrix2D &M) {
    return (M(0,0) * M(1,1)  - M(0,1) * M(1,0));
}

///----------------------------------------------------------------------------
///3D:

Matrix3D operator*(const Matrix3D& A, const Matrix3D& B) {
    return(Matrix3D(
            A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
            A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1),
            A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2),

            A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
            A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
            A(1,0) * B(0,2) + A(1,2) * B(1,2) + A(1,2) * B(2,2),

            A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
            A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
            A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2)
    ));
}

Vector3D operator*(const Matrix3D &M, const Vector3D &v) {
    return (Vector3D(M(0,0) * v.x + M(0,1) * v.y + M(0,2) * v.z,
                     M(1,0) * v.x + M(1,1) * v.y + M(1,2) * v.z,
                     M(2,0) * v.x + M(2,1) * v.y + M(2,2) * v.z
            ));
}

Matrix3D operator*(float s, const Matrix3D &M) {
    return (Matrix3D(s * M(0,0), s * M(0,1), s * M(0,2),
                     s * M(1,0), s * M(1,1), s * M(1,2),
                     s * M(2,0), s * M(2,1), s * M(2,2)
    ));
}
Matrix3D operator*(const Matrix3D &M, float s) {
    return (Matrix3D(s * M(0,0), s * M(0,1), s * M(0,2),
                     s * M(1,0), s * M(1,1), s * M(1,2),
                     s * M(2,0), s * M(2,1), s * M(2,2)
    ));
}

Matrix3D Transpose(const Matrix3D &M) {
    return (Matrix3D(M(0,0), M(1,0), M(2,0),
                     M(0,1), M(1,1), M(2,1),
                     M(0,2), M(1,2), M(2,2)
            ));
}

Matrix3D operator+(const Matrix3D &A, const Matrix3D &B) {
    return (Matrix3D(A(0,0) + B(0,0), A(0,1) + B(0,1), A(0,2) + B(0,2),
                     A(1,0) + B(1,0), A(1,1) + B(1,1), A(1,2) + B(1,2),
                     A(2,0) + B(2,0), A(2,1) + B(2,1), A(2,2) + B(2,2)
    ));
}

Matrix3D operator-(const Matrix3D& A, const Matrix3D& B) {
    return (Matrix3D(A(0,0) - B(0,0), A(0,1) - B(0,1), A(0,2) - B(0,2),
                     A(1,0) - B(1,0), A(1,1) - B(1,1), A(1,2) - B(1,2),
                     A(2,0) - B(2,0), A(2,1) - B(2,1), A(2,2) - B(2,2)
    ));
}

float Determinant(const Matrix3D &M) {
    return (M(0,0) * (M(1,1) * M(2,2) - M(1,2) * M(2,1))
            + M(0,1) * (M(1,2) * M(2,0) - M(1,0) * M(2,2))
            + M(0,2) * (M(1,0) * M(2,1) - M(1,1) * M(2,0)));
}

///-------------------------------------------------------------------------------------------------
///4D:
Matrix4D operator*(const Matrix4D &A, const Matrix4D &B) {
    return (Matrix4D(A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0) + A(0,3) * B(3,0),
                     A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1) + A(0,3) * B(3,1),
                     A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2) + A(0,3) * B(3,2),
                     A(0,0) * B(0,3) + A(0,1) * B(1,3) + A(0,2) * B(2,3) + A(0,3) * B(3,3),

                     A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0) + A(1,3) * B(3,0),
                     A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1) + A(1,3) * B(3,1),
                     A(1,0) * B(0,2) + A(1,2) * B(1,2) + A(1,2) * B(2,2) + A(1,3) * B(3,2),
                     A(1,0) * B(0,3) + A(1,2) * B(1,3) + A(1,2) * B(2,3) + A(1,3) * B(3,3),

                     A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0) + A(2,3) * B(3,0),
                     A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1) + A(2,3) * B(3,1),
                     A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2) + A(2,3) * B(3,2),
                     A(2,0) * B(0,3) + A(2,1) * B(1,3) + A(2,2) * B(2,3) + A(2,3) * B(3,3),

                     A(3,0) * B(0,0) + A(3,1) * B(1,0) + A(3,2) * B(2,0) + A(3,3) * B(3,0),
                     A(3,0) * B(0,1) + A(3,1) * B(1,1) + A(3,2) * B(2,1) + A(3,3) * B(3,1),
                     A(3,0) * B(0,2) + A(3,1) * B(1,2) + A(3,2) * B(2,2) + A(3,3) * B(3,2),
                     A(3,0) * B(0,3) + A(3,1) * B(1,3) + A(3,2) * B(2,3) + A(3,3) * B(3,3)
            ));
}

Vector4D operator*(const Matrix4D &M, const Vector4D &v) {
    return (Vector4D(M(0,0) * v.x + M(0,1) * v.y + M(0,2) * v.z + M(0,3) * v.w,
                     M(1,0) * v.x + M(1,1) * v.y + M(1,2) * v.z + M(1,3) * v.w,
                     M(2,0) * v.x + M(2,1) * v.y + M(2,2) * v.z + M(2,3) * v.w,
                     M(3,0) * v.x + M(3,1) * v.y + M(3,2) * v.z + M(3,3) * v.w
            ));
}

Matrix4D operator*(float s, const Matrix4D &M) {
    return (Matrix4D(s * M(0,0), s * M(0,1), s * M(0,2), s * M(0,3),
                     s * M(1,0), s * M(1,1), s * M(1,2), s * M(1,3),
                     s * M(2,0), s * M(2,1), s * M(2,2), s * M(2,3),
                     s * M(3,0), s * M(3,1), s * M(3,2), s * M(3,3)
    ));
}
Matrix4D operator*(const Matrix4D &M, float s) {
    return (Matrix4D(s * M(0,0), s * M(0,1), s * M(0,2), s * M(0,3),
                     s * M(1,0), s * M(1,1), s * M(1,2), s * M(1,3),
                     s * M(2,0), s * M(2,1), s * M(2,2), s * M(2,3),
                     s * M(3,0), s * M(3,1), s * M(3,2), s * M(3,3)
    ));
}


Matrix4D Transpose(const Matrix4D& M) {
    return (Matrix4D(M(0,0), M(1,0), M(2,0), M(3,0),
                     M(0,1), M(1,1), M(2,1), M(3,1),
                     M(0,2), M(1,2), M(2,2), M(3,2),
                     M(0,3), M(1,3), M(2,3), M(3,3)
    ));
}

Matrix4D operator+(const Matrix4D &A, const Matrix4D &B) {
    return (Matrix4D(A(0,0) + B(0,0), A(0,1) + B(0,1), A(0,2) + B(0,2), A(0,3) + B(0,3),
                     A(1,0) + B(1,0), A(1,1) + B(1,1), A(1,2) + B(1,2), A(1,3) + B(1,3),
                     A(2,0) + B(2,0), A(2,1) + B(2,1), A(2,2) + B(2,2), A(2,3) + B(2,3),
                     A(3,0) + B(3,0), A(3,1) + B(3,1), A(3,2) + B(3,2), A(3,3) + B(3,3)
            ));
}

Matrix4D operator-(const Matrix4D &A, const Matrix4D &B) {
    return (Matrix4D(A(0,0) - B(0,0), A(0,1) - B(0,1), A(0,2) - B(0,2), A(0,3) - B(0,3),
                     A(1,0) - B(1,0), A(1,1) - B(1,1), A(1,2) - B(1,2), A(1,3) - B(1,3),
                     A(2,0) - B(2,0), A(2,1) - B(2,1), A(2,2) - B(2,2), A(2,3) - B(2,3),
                     A(3,0) - B(3,0), A(3,1) - B(3,1), A(3,2) - B(3,2), A(3,3) - B(3,3)
    ));
}

float Determinant(const Matrix4D &m) {
    return (
                m(0,3) * m(1,2) * m(2,1) * m(3,0) - m(0,2) * m(1,3) * m(2,1) * m(3,0)-
                m(0,3) * m(1,1) * m(2,2) * m(3,0) + m(0,1) * m(1,3) * m(2,2) * m(3,0)+
                m(0,2) * m(1,1) * m(2,3) * m(3,0) - m(0,1) * m(1,2) * m(2,3) * m(3,0)-
                m(0,3) * m(1,2) * m(2,0) * m(3,1) + m(0,2) * m(1,3) * m(2,0) * m(3,1)+
                m(0,3) * m(1,0) * m(2,2) * m(3,1) - m(0,0) * m(1,3) * m(2,2) * m(3,1)-
                m(0,2) * m(1,0) * m(2,3) * m(3,1) + m(0,0) * m(1,2) * m(2,3) * m(3,1)+
                m(0,3) * m(1,1) * m(2,0) * m(3,2) - m(0,1) * m(1,3) * m(2,0) * m(3,2)-
                m(0,3) * m(1,0) * m(2,1) * m(3,2) + m(0,0) * m(1,3) * m(2,1) * m(3,2)+
                m(0,1) * m(1,0) * m(2,3) * m(3,2) - m(0,0) * m(1,1) * m(2,3) * m(3,2)-
                m(0,2) * m(1,1) * m(2,0) * m(3,3) + m(0,1) * m(1,2) * m(2,0) * m(3,3)+
                m(0,2) * m(1,0) * m(2,1) * m(3,3) - m(0,0) * m(1,2) * m(2,1) * m(3,3)-
                m(0,1) * m(1,0) * m(2,2) * m(3,3) + m(0,0) * m(1,1) * m(2,2) * m(3,3)
            );
}

#include "my_gauss.h"

float Determinant(const Matrix &M) {
    Matrix tempM(M);
    Gauss::Eliminate(tempM);
    return 0;
}


Matrix &Matrix::operator=(const Matrix &M) {
    if (this != &M) {
        for (int c = 0; c < column; c++) {
            for (int r = 0; r < row; r++) {
                (*this)(r,c) = M(r, c);
            }
        }
    }
    return *this;
}

Matrix &Matrix::copyWithResize(const Matrix &M) {
    if (this != &M) {
        row = M.row;
        column = M.column;
        delete [] n;
        n = new float[row * column];

        for (int c = 0; c < column; c++) {
            for (int r = 0; r < row; r++) {
                (*this)(r,c) = M(r, c);
            }
        }
    }
    return *this;
}
