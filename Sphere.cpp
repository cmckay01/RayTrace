#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Vector& center, double radius, const Vector& color, double specular, double reflective)
    : center(center), radius(radius), color(color), specular(specular), reflective(reflective) {}

bool Sphere::intersect(const Ray& ray, double& t) const {
    Vector oc = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2.0 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    } else {
        t = (-b - sqrt(discriminant)) / (2.0 * a);
        return true;
    }
}

Vector Sphere::getNormal(const Vector& point) const {
    return (point - center).normalize();
}