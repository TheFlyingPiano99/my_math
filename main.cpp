#include <iostream>

#include "my_math.h"

int main() {
    std::cout << "Test" << std::endl;

    Matrix<4,4> mx1{};
    Matrix<4, 3> mx2{};
    Matrix<4, 3> mx3{};

    mx3 = mx1 * mx2;

    mx1.fill(5);
    mx2.fill(2);
    mx3.fill(1);

    Vector3D v1(1,1,1);
    Vector3D v2(0,-1,0);

    //Operations:

    Matrix3D mx4(v1,v1, v1);
    Matrix3D mx5(v1,v2, v1);
    mx4 = mx4 * mx5;

    //Output:
    std::cout << mx4(0,0) << ", " << mx4(0,1) <<  std::endl;
    std::cout << v2.x << ", " << v2.y << ", " << v2.z << std::endl;

    return 0;
}
