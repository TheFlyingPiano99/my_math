//
// Created by simon on 2020. 05. 25..
//

#ifndef LEGITARSASAG_FUNCTIONS_H
#define LEGITARSASAG_FUNCTIONS_H

#include <cmath>
    class Functions {
        double amp;
        double omega1;
        double omega2;
    public:
        Functions(double a = 1, double o1 = 1, double o2 = 1) : amp(a), omega1(o1), omega2(o2) {}

        double sin(double t) {
            return amp * std::sin(omega1 * t);
        }

        double cos(double t) {
            return amp * std::cos(omega2 * t);
        }

        double sin_sin(double t) {
            return amp * (std::sin(omega1 * t) + std::sin(omega2 * t));
        }

        void setAmp(double a) {
            amp = a;
        }


        void setOmega1(double o) {
            omega1 = o;
        }

        void setOmega2(double o) {
            omega1 = o;
        }
    };

#include "my_vector.h"

///Transform:
    float abs_vector(Vector4D k);

    Vector4D norm_vector(Vector4D a);

///Multiplication:
    float dot_product(Vector4D a, Vector4D b);

    Vector4D cross_product(Vector4D a, Vector4D b);

///Trigonometry:
    float sin(Vector4D v1, Vector4D v2);

    float cos(Vector4D v1, Vector4D v2);

#endif //LEGITARSASAG_FUNCTIONS_H
