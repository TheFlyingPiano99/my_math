//
// Created by simon on 2020. 05. 26..
//

#include <stdexcept>
#include "my_matrix.h"
#include "Analise.h"

template<>
void Matrix<float>::clear() {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            mx[i][j] = 0.0;
        }
    }
}

template<>
Matrix<float> Matrix<float>::operator*(Matrix<float> &mx2) {
    size_t c1r2 = getColumnN();
    if (c1r2 != mx2.getRowN()) {
        throw "Hibas meretu matrix!";
    }

    size_t r1 = getRowN();
    size_t c2 = mx2.getColumnN();

    Matrix<float> retM(r1, c2);

    for (size_t i = 0; i < r1; i++) {
        for (size_t  j = 0; j < c2; j++) {
            for (size_t  k = 0; k < c1r2; k++) {
                retM[i][j] = (*this)[i][k] * mx2[k][j];
            }
        }
    }

    return retM;
}

template<typename t>
void Matrix<t>::fill(t val) {
    for (size_t r = 0; r < row; r++) {
        for (size_t c = 0; c < column; c++) {
            mx[r][c] = val;
        }
    }
}

template<>
void Matrix<float>::fill(float val) {
    for (size_t r = 0; r < row; r++) {
        for (size_t c = 0; c < column; c++) {
            mx[r][c] = val;
        }
    }
}

template<>
void Matrix<double>::clear() {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            mx[i][j] = 0.0;
        }
    }
}

template<>
void Matrix<int>::clear() {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            mx[i][j] = 0;
        }
    }
}

///Global:
std::ostream &operator<<(std::ostream& os, const Matrix<float>& mx) {
    size_t row = mx.getRowN();
    size_t column = mx.getColumnN();
    for (size_t r = 0; r < row; r++) {
        for (size_t c = 0; c < column; c++) {
            os << mx[r][c];
            if (column-1 != c) {
                os << " | ";
            }
        }
        os << std::endl;
    }
    return os;
}

