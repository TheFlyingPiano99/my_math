#include <iostream>

#include "my_math.h"

int main() {
    std::cout << "Test" << std::endl;

    ///Koordinata---------------------------------------------
    Vector4D vect1 (1,2,4,7);

    std::cout << "vect1: x=" << vect1.x << ", y=" << vect1.y << ", z=" << vect1.z << ", w=" << vect1.w << std::endl;

    Vector4D vect2(0.5,0,0,0);

    std::cout << "vect2: x=" << vect2.x << ", y=" << vect2.y << ", z=" << vect2.z << ", w=" << vect2.w << std::endl;
    float s = sin(vect1, vect2);
    std::cout << "sin="<< s <<std::endl;

    float c = cos(vect1, vect2);
    std::cout << "cos=" << c <<std::endl;


    ///Matrix-------------------------------------------------
    Matrix<10, 10> mx1;
    Matrix<10, 12> mx2;

    //mx1.fill(8);
    //mx2.fill(2);

//    Matrix<10, 12> mx3 = mx1 * mx2;

    //std::cout << mx3;

    ///Small matrices:
    Matrix3D mx3d(1,0,0,0,1,0,0,0,1);
    Matrix4D mx4d(1,0,0,0,
                  0,1,0,0,
                  0,0,1,0,
                  0,0,0,1
            );


    vect1 = mx4d * vect1;
    std::cout << "vect1: x=" << vect1.x << ", y=" << vect1.y << ", z=" << vect1.z << ", w=" << vect1.w << std::endl;

    return 0;
}
