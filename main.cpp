#include <iostream>

#include "my_math.h"

int main() {
    std::cout << "Test" << std::endl;

    ///Koordinata---------------------------------------------
    Vector4D vect1 (1,0,0,0);

    std::cout << "vect1: x=" << vect1.x << ", y=" << vect1.y << ", z=" << vect1.z << ", w=" << vect1.w << std::endl;

    Vector4D vect2(0.5,0,0,0);

    std::cout << "vect2: x=" << vect2.x << ", y=" << vect2.y << ", z=" << vect2.z << ", w=" << vect2.w << std::endl;
    vect1 = vect1 * 5;
    float s = sin(vect1, vect2);
    std::cout << "sin="<< s <<std::endl;

    float c = cos(vect1, vect2);
    std::cout << "cos=" << c <<std::endl;


    ///Matrix-------------------------------------------------
    Matrix<float> mx1(10,10);
    Matrix<float> mx2(10,12);
    mx1.clear();
    mx2.clear();

    mx1.fill(8);
    mx2.fill(2);

    mx1 = mx1 * mx2;

    std::cout << mx1;


    return 0;
}