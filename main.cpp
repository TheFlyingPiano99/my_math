#include <iostream>

#include "my_math.h"

int main() {
    std::cout << "Test" << std::endl;

    Matrix<4,4> mx1{};
    Matrix<4, 3> mx2{};
    Matrix<4, 3> mx3{};
    mx1.fill(5);
    mx2.fill(2);
    mx3.fill(1);

    Vector<4> v1{};
    Vector<4> v2{};
    v1[0] = 2; v1[1] = 2; v1[2] = 1; v1[3] = 1;
    v2[0] = 2; v2[1] = 2; v2[2] = 1; v2[3] = 2;

    mx1 = mx1 * 10;
    mx1(3, 0) = 0;
    mx1 = mx1 - mx1;
    v1 = mx1[0];
    std::cout << mx1 << std::endl;
    std::cout << v1 << std::endl;

    /*
    v1 = v1 - v2;
    float s = Magnitude(v1);

    std::cout << v1 << std::endl;
    std::cout << s << std::endl;
     */

    return 0;
}
