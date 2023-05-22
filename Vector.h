#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector {
public:
    double x, y, z;

    Vector(double x = 0, double y = 0, double z = 0);
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator*(double s) const;
    double dot(const Vector& v) const;
    Vector cross(const Vector& v) const;
    Vector normalize() const;

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        // Implement the output formatting for Vector objects
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }
};

#endif