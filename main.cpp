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

    Vector2D v1(1,10);
    Vector2D v2(0,-10);

    //Operations:

    Matrix2D mx4(v1,v2);
    Matrix2D mx5(v1,v2);
    //mx4 = mx4 * mx5;

    Vector4D v4(0,0,0,0);
    Matrix4D mx6(v4,v4,v4,v4);

    Vector3D v5(0,0,1);
    Vector3D v6(10,0,0);
    Vector3D v7(0,1,0);
    Matrix3D mx7(v6, v7, v5);


    std::cout << Determinant(mx4) << std::endl;
    std::cout << Determinant(mx7) << std::endl;
    std::cout << Determinant(mx6) << std::endl;

    //Output:
    std::cout << mx4(0,0) << ", " << mx4(0,1) <<  std::endl;
    std::cout << v2.x << ", " << v2.y << std::endl;

    return 0;
}
