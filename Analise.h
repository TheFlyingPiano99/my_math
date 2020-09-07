//
// Created by simon on 2020. 05. 25..
//

#ifndef LEGITARSASAG_ANALISE_H
#define LEGITARSASAG_ANALISE_H
#include <cmath>
#include "my_matrix.h"
//#include <vector>

class vector;

class Functions;

class Analiser {

    template<unsigned int r, unsigned int c>
    void create_discrete_fourier_transform_mx (const std::complex<float>& omega, Matrix<r, c>& ebbe);

public:
    Analiser() {}


    template<unsigned int r, unsigned int c>
    void discrete_fourier_transform(Matrix<r, c>& f, Matrix<r, c>& f_transform);

    void discrete_fourier_transform_sajat(std::vector<float>& f, std::vector<float>& f_transform);

};

#endif //LEGITARSASAG_ANALISE_H
