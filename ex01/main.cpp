#include "../includes/Vector.hpp"

int main() {
    // Subject example 1
    Vector<float> e1 = {1, 0, 0};
    Vector<float> e2 = {0, 1, 0};
    Vector<float> e3 = {0, 0, 1};

    std::vector<Vector<float>> vectors = {e1, e2, e3};
    std::vector<float> coefficients = {10, -2, 0.5};

    Vector<float> result = linear_combination(vectors, coefficients);
    result.print();                      // [10.0] [-2.0] [0.5]

    // Subject example 2
    Vector<float> v1 = {1, 2, 3};
    Vector<float> v2 = {0, 10, -100};

    std::vector<Vector<float>> vectors2 = {v1, v2};
    std::vector<float> coefficients2 = {10, -2};

    linear_combination(vectors2, coefficients2).print();   // [10.0] [0.0] [230.0]

    return 0;
}