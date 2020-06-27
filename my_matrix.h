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

class Matrix4x4 {
    float mx[4][4];
public:

};

#endif //LEGITARSASAG_MATRIX_H
