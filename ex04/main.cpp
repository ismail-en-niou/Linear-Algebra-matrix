#include "../includes/Vector.hpp"
#include "../includes/Matrix.hpp"

#include <iostream>
#include <iomanip>

void printNorms(const Vector<float> &u) {
    std::cout << std::setprecision(9) << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;
}

int main() {
    printNorms(Vector<float>{0, 0, 0});     // 0, 0, 0
    printNorms(Vector<float>{1, 2, 3});     // 6, 3.74165738, 3
    printNorms(Vector<float>{-1, -2});      // 3, 2.23606798, 2
    return 0;
}