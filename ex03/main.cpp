#include <iostream>
#include "Vector.hpp"

// Prints a number like the subject: 9 -> "9.0", 4.5 -> "4.5"
void printScalar(float x) {
    if (x == (int)x)
        std::cout << x << ".0" << std::endl;
    else
        std::cout << x << std::endl;
}

void title(const char *name) {
    std::cout << std::endl << "===== " << name << " =====" << std::endl;
}

int main() {
    // =====================================================
    //  PART 1 - SUBJECT EXAMPLES (must match exactly)
    // =====================================================

    title("Subject: [0, 0] . [1, 1] -> 0.0");
    {
        Vector<float> u = {0, 0};
        Vector<float> v = {1, 1};
        printScalar(u.dot(v));
    }

    title("Subject: [1, 1] . [1, 1] -> 2.0");
    {
        Vector<float> u = {1, 1};
        Vector<float> v = {1, 1};
        printScalar(u.dot(v));
    }

    title("Subject: [-1, 6] . [3, 2] -> 9.0");
    {
        Vector<float> u = {-1, 6};
        Vector<float> v = {3, 2};
        printScalar(u.dot(v));
    }

    // =====================================================
    //  PART 2 - MY OWN TESTS
    // =====================================================

    title("Perpendicular: [1, 0] . [0, 1] -> 0.0");
    {
        Vector<float> u = {1, 0};
        Vector<float> v = {0, 1};
        printScalar(u.dot(v));
    }

    title("Perpendicular (not obvious): [2, 3] . [-3, 2] -> 0.0");
    {
        Vector<float> u = {2, 3};
        Vector<float> v = {-3, 2};
        printScalar(u.dot(v));
    }

    title("Same direction: [1, 2] . [2, 4] -> 10.0 (positive)");
    {
        Vector<float> u = {1, 2};
        Vector<float> v = {2, 4};
        printScalar(u.dot(v));
    }

    title("Opposite direction: [1, 2] . [-1, -2] -> -5.0 (negative)");
    {
        Vector<float> u = {1, 2};
        Vector<float> v = {-1, -2};
        printScalar(u.dot(v));
    }

    title("With itself = length squared: [3, 4] . [3, 4] -> 25.0");
    {
        Vector<float> u = {3, 4};
        printScalar(u.dot(u));
    }

    title("Commutative: u.v == v.u -> 32.0 and 32.0");
    {
        Vector<float> u = {1, 2, 3};
        Vector<float> v = {4, 5, 6};
        printScalar(u.dot(v));
        printScalar(v.dot(u));
    }

    title("Decimals: [0.5, 1.5] . [2, 2] -> 4.0");
    {
        Vector<float> u = {0.5, 1.5};
        Vector<float> v = {2, 2};
        printScalar(u.dot(v));
    }

    title("Decimals result: [0.5, 0.25] . [1, 1] -> 0.75");
    {
        Vector<float> u = {0.5, 0.25};
        Vector<float> v = {1, 1};
        printScalar(u.dot(v));
    }

    title("1 element: [7] . [3] -> 21.0");
    {
        Vector<float> u = {7};
        Vector<float> v = {3};
        printScalar(u.dot(v));
    }

    title("Zero vector: [0, 0, 0] . [5, -2, 9] -> 0.0");
    {
        Vector<float> u = {0, 0, 0};
        Vector<float> v = {5, -2, 9};
        printScalar(u.dot(v));
    }

    title("Basis vectors pick a coordinate: [4, -7, 2] . e2 -> -7.0");
    {
        Vector<float> u = {4, -7, 2};
        Vector<float> e2 = {0, 1, 0};
        printScalar(u.dot(e2));
    }

    title("u is not modified by dot: u stays [1.0] [2.0]");
    {
        Vector<float> u = {1, 2};
        Vector<float> v = {3, 4};
        u.dot(v);
        u.print();
    }

    return 0;
}