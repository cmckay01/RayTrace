#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"
#include "Vector.h"

class Sphere : public Object {
public:
    Vector center;
    double radius;
    Vector color;  // Add color
    double specular;  // Add specular
    double reflective;  // Add reflective
    
    Vector getNormal(const Vector& point) const;

    Sphere(const Vector& center, double radius, const Vector& color, double specular, double reflective);
    bool intersect(const Ray& ray, double& t) const override;
};

#endif