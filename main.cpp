#include <iostream>

#include "my_math.h"

int main() {
    std::cout << "Test" << std::endl;

    ///Koordinata---------------------------------------------
    Vector3D vect1 (1,2,4);
    Vector2D v2d(1,2);
    float mag = Magnitude(v2d);

    std::cout << "vect1: x=" << vect1.x << ", y=" << vect1.y << ", z=" << vect1.z << std::endl;

    Vector3D vect2(0.5,0,0);
    vect1 = vect1 * 10;
    std::cout << "vect2: x=" << vect2.x << ", y=" << vect2.y << ", z=" << vect2.z << std::endl;
    float s = Sin(vect1, vect2);
    std::cout << "sin="<< s <<std::endl;
    s = Cos(vect1, vect2);
    std::cout << "cos="<< s <<std::endl;



    ///Matrices:
    Matrix<10, 10> mx1{};
    Matrix<10, 12> mx2{};

    mx1.fill(3);
    mx2.fill(2);

    Matrix<10, 12> mx3 = mx1 * mx2;

    std::cout << mx3;

    ///Small matrices:
    Matrix3D mx3d(1,0,0,0,1,0,0,0,1);
    Matrix4D mx4d(1,0,0,0,
                  0,1,0,0,
                  0,0,1,0,
                  0,0,0,1
            );

    Vector4D vect3(1,2,3,4);
    vect3 = mx4d * vect3;
    std::cout << "vect1: x=" << vect3.x << ", y=" << vect3.y << ", z=" << vect3.z << ", w=" << vect3.w << std::endl;

    return 0;
}
