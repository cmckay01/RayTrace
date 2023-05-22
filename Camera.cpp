#include "Camera.h"

Camera::Camera(const Vector& position) : position(position) {}

Ray Camera::getRay(double x, double y) const {
    Vector direction = Vector(x, y, -1).normalize(); // change 1 to -1
    return Ray(position, direction);
}
