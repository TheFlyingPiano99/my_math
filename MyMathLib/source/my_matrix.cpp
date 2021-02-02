//
// Created by simon on 2020. 05. 26..
//

#include <stdexcept>
#include "../include/my_matrix.h"

#include <algorithm>


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

Matrix2D Inverse(const Matrix2D &M) {
    float invDet = 1.0f / Determinant(M);
    return Matrix2D(
                M(1,1) * invDet, -M(0,1) * invDet,
               -M(1,0) * invDet,  M(0,0) * invDet
            );
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

Matrix3D Inverse(const Matrix3D &M) {
    const Vector3D& a = M[0];
    const Vector3D& b = M[1];
    const Vector3D& c = M[2];

    Vector3D r0 = Cross(b, c);
    Vector3D r1 = Cross(c, a);
    Vector3D r2 = Cross(a, b);

    float invDet = 1.0f / Dot(r2, c);

    return Matrix3D(
                r0.x * invDet, r0.y * invDet, r0.z * invDet,
                r1.x * invDet, r1.y * invDet, r1.z * invDet,
                r2.x * invDet, r2.y * invDet, r2.z * invDet
            );
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

Matrix4D Inverse(const Matrix4D &M) {
    const Vector3D& a = reinterpret_cast<const Vector3D&>(M[0]);
    const Vector3D& b = reinterpret_cast<const Vector3D&>(M[1]);
    const Vector3D& c = reinterpret_cast<const Vector3D&>(M[2]);
    const Vector3D& d = reinterpret_cast<const Vector3D&>(M[3]);

    const float& x = M(3,0);
    const float& y = M(3,1);
    const float& z = M(3,2);
    const float& w = M(3,3);

    Vector3D s = Cross(a, b);
    Vector3D t = Cross(c, d);
    Vector3D u = a * y - b * x;
    Vector3D v = c * w - d * z;

    float invDet = 1.0f / (Dot(s, v) + Dot(t, u));
    s *= invDet;
    t *= invDet;
    u *= invDet;
    v *= invDet;

    Vector3D r0 = Cross(b, v) + t * y;
    Vector3D r1 = Cross(v, a) - t * x;
    Vector3D r2 = Cross(d, u) + s * w;
    Vector3D r3 = Cross(u, c) - s * z;

    return Matrix4D(
                r0.x, r0.y, r0.z, -Dot(b, t),
                r1.x, r1.y, r1.z,  Dot(a, t),
                r2.x, r2.y, r2.z, -Dot(d, s),
                r3.x, r3.y, r3.z,  Dot(c, s)
            );
}

///-----------------------------------------------------------------------------------

/*
#include "my_gauss.h"

float Determinant(const Matrix &M) {
    Matrix tempM(M);
    Gauss::Eliminate(tempM);
    return 0;
}
*/

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

void RemoveColumns(Matrix& M, std::vector<int> toRemoveIndexes) {
    Matrix tempM(M.row, M.column - toRemoveIndexes.size());

    int ct = 0; //Index of the temp matrix.
    for (int c = 0; c < M.column; c++) {
        if (toRemoveIndexes.end() == std::find(toRemoveIndexes.begin(), toRemoveIndexes.end(), c)) {
            for (int i = 0; i < M.row; i++) {
                tempM(i, ct) = M(i, c);
            }
            ct++;
        }
    }
    M.copyWithResize(tempM);
}

Matrix Identity(int size) {
    Matrix retM(size, size);
    retM.fill(0);
    for (int i = 0; i < size; i++) {
        retM(i,i) = 1.0f;
    }
    return retM;
}

Matrix Diagonal(const Vector& v) {
    Matrix retM(v.dimension, v.dimension);
    retM.fill(0);
    for (int i = 0; i < v.dimension; i++) {
        retM(i,i) = v[i];
    }
    return retM;
}

void RemoveRows(Matrix &M, std::vector<int> toRemoveIndexes) {
    Matrix tempM(M.row - toRemoveIndexes.size(), M.column);

    int rt = 0; //Index of the temp matrix.
    for (int r = 0; r < M.row; r++) {
        if (toRemoveIndexes.end() == std::find(toRemoveIndexes.begin(), toRemoveIndexes.end(), r)) {
            for (int i = 0; i < M.column; i++) {
                tempM(rt, i) = M(r, i);
            }
            rt++;
        }
    }
    M.copyWithResize(tempM);

}

Matrix MultiplyRow(const Matrix& M, const int row, const  float val) {
    Matrix retM(M.row, M.column);
    for (int c = 0; c < M.column; c++) {
        retM(row, c) = M(row, c) * val;
    }
    return retM;
}

Matrix MultipyColumn(const Matrix& M, const int column, const  float val) {
    Matrix retM(M.row, M.column);
    for (int r = 0; r < M.row; r++) {
        retM(r, column) = M(r, column) * val;
    }
    return retM;
}
