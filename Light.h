#ifndef LIGHT_H
#define LIGHT_H

#include "Vector.h"

class Light {
public:
    Vector position;
    Vector intensity;  // Add intensity

    Light(const Vector& position, const Vector& intensity);
};

#endif
