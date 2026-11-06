#include <iostream>
#include "../includes/Vector.hpp"
#include "../includes/Matrix.hpp"

void title(const char *name) {
    std::cout << std::endl << "===== " << name << " =====" << std::endl;
}

int main() {
    // =====================================================
    //  PART 1 - SUBJECT EXAMPLES (must match exactly)
    // =====================================================

    title("Subject: Vector add  -> [7.0] [10.0]");
    {
        Vector<float> u = {2, 3};
        Vector<float> v = {5, 7};
        u.add(v);
        u.print();
    }

    title("Subject: Vector sub  -> [-3.0] [-4.0]");
    {
        Vector<float> u = {2, 3};
        Vector<float> v = {5, 7};
        u.sub(v);
        u.print();
    }

    title("Subject: Vector scl  -> [4.0] [6.0]");
    {
        Vector<float> u = {2, 3};
        u.scl(2);
        u.print();
    }

    title("Subject: Matrix add  -> [8.0, 6.0] [1.0, 6.0]");
    {
        Matrix<float> u = {{1, 2}, {3, 4}};
        Matrix<float> v = {{7, 4}, {-2, 2}};
        u.add(v);
        u.print();
    }

    title("Subject: Matrix sub  -> [-6.0, -2.0] [5.0, 2.0]");
    {
        Matrix<float> u = {{1, 2}, {3, 4}};
        Matrix<float> v = {{7, 4}, {-2, 2}};
        u.sub(v);
        u.print();
    }

    title("Subject: Matrix scl  -> [2.0, 4.0] [6.0, 8.0]");
    {
        Matrix<float> u = {{1, 2}, {3, 4}};
        u.scl(2);
        u.print();
    }

    // =====================================================
    //  PART 2 - MY OWN TESTS (edge cases for the defense)
    // =====================================================

    title("Vector with decimals: [1.5, 2.25] + [0.5, 0.75] -> [2.0] [3.0]");
    {
        Vector<float> u = {1.5, 2.25};
        Vector<float> v = {0.5, 0.75};
        u.add(v);
        u.print();
    }

    title("Vector 1 element: [42] - [2] -> [40.0]");
    {
        Vector<float> u = {42};
        Vector<float> v = {2};
        u.sub(v);
        u.print();
    }

    title("Vector 5 elements: [1,2,3,4,5] + [5,4,3,2,1] -> all [6.0]");
    {
        Vector<float> u = {1, 2, 3, 4, 5};
        Vector<float> v = {5, 4, 3, 2, 1};
        u.add(v);
        u.print();
    }

    title("u - u = zero vector -> [0.0] [0.0] [0.0]");
    {
        Vector<float> u = {3, -7, 12};
        Vector<float> copy = u;
        u.sub(copy);
        u.print();
    }

    title("Scale by 0.5: [3, 5] -> [1.5] [2.5]");
    {
        Vector<float> u = {3, 5};
        u.scl(0.5);
        u.print();
    }

    title("Scale by -1: [2, -3] -> [-2.0] [3.0]");
    {
        Vector<float> u = {2, -3};
        u.scl(-1);
        u.print();
    }

    title("Scale by 1 (nothing changes): [4, 9] -> [4.0] [9.0]");
    {
        Vector<float> u = {4, 9};
        u.scl(1);
        u.print();
    }

    title("Scale by 0: [4, 9] -> [0.0] [0.0]");
    {
        Vector<float> u = {4, 9};
        u.scl(0);
        u.print();
    }

    title("Commutativity: u + v == v + u -> both [7.0] [10.0]");
    {
        Vector<float> u = {2, 3};
        Vector<float> v = {5, 7};
        Vector<float> a = u;  a.add(v);
        Vector<float> b = v;  b.add(u);
        a.print();
        b.print();
    }

    title("Chaining: ([1,1] + [2,2]) * 3 -> [9.0] [9.0]");
    {
        Vector<float> u = {1, 1};
        Vector<float> v = {2, 2};
        u.add(v);
        u.scl(3);
        u.print();
    }

    title("Original vector not modified: v stays [5.0] [7.0]");
    {
        Vector<float> u = {2, 3};
        Vector<float> v = {5, 7};
        u.add(v);
        v.print();
    }

    title("Matrix 2x3 (not square) add -> [2.0, 4.0, 6.0] [8.0, 10.0, 12.0]");
    {
        Matrix<float> u = {{1, 2, 3}, {4, 5, 6}};
        Matrix<float> v = {{1, 2, 3}, {4, 5, 6}};
        u.add(v);
        u.print();
    }

    title("Matrix 3x1 sub -> [0.0] [-1.0] [-2.0]");
    {
        Matrix<float> u = {{1}, {1}, {1}};
        Matrix<float> v = {{1}, {2}, {3}};
        u.sub(v);
        u.print();
    }

    title("Matrix 3x3 scale by 0.5 -> [0.5, 1.0, 1.5] ...");
    {
        Matrix<float> u = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        u.scl(0.5);
        u.print();
    }

    title("Matrix with negatives: [[-1,-2],[-3,-4]] * -2 -> [2.0, 4.0] [6.0, 8.0]");
    {
        Matrix<float> u = {{-1, -2}, {-3, -4}};
        u.scl(-2);
        u.print();
    }

    title("Matrix A - A = zero -> [0.0, 0.0] [0.0, 0.0]");
    {
        Matrix<float> u = {{5, 6}, {7, 8}};
        Matrix<float> copy = u;
        u.sub(copy);
        u.print();
    }

    return 0;
}