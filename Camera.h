#ifndef CAMERA_H
#define CAMERA_H

#include "Vector.h"
#include "Ray.h"

class Camera {
public:
    Vector position;

    Camera(const Vector& position);
    Ray getRay(double x, double y) const;
};

#endif
