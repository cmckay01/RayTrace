#include "Vector.h"
#include <iostream>

int main() {
    Vector v1(1, 0, 0);
    Vector v2(0, 1, 0);
    double dotProduct = v1.dot(v2);
    std::cout << "Dot product: " << dotProduct << std::endl;
    return 0;
}