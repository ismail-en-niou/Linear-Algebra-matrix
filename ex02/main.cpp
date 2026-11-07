#include <iostream>
#include "../includes/Vector.hpp"
#include "../includes/Matrix.hpp"
#include "../includes/Lerp.hpp"

int main() {
    std::cout << lerp(0.f, 1.f, 0.f) << std::endl;      // 0
    std::cout << lerp(0.f, 1.f, 1.f) << std::endl;      // 1
    std::cout << lerp(0.f, 1.f, 0.5f) << std::endl;     // 0.5
    std::cout << lerp(21.f, 42.f, 0.3f) << std::endl;   // 27.3

    Vector<float> u = {2, 1};
    Vector<float> v = {4, 2};
    lerp(u, v, 0.3f).print();                           // [2.6] [1.3]

    Matrix<float> a = {{2, 1}, {3, 4}};
    Matrix<float> b = {{20, 10}, {30, 40}};
    lerp(a, b, 0.5f).print();                           // [11.0, 5.5] [16.5, 22.0]

    return 0;
}