#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object.h"
#include "Ray.h"
#include"Vector.h"
#include "Light.h"

class Scene {
public:
    std::vector<Object*> objects;

    void add(Object* object);
    bool intersect(const Ray& ray, double& t, Object*& object) const;
    Vector getLighting(const Vector& point, const Vector& normal, const Light& light) const;
};

#endif
