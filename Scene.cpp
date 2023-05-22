#include "Scene.h"
#include <cmath>
#include <iostream>

void Scene::add(Object* object) {
    objects.push_back(object);
}

bool Scene::intersect(const Ray& ray, double& t, Object*& object) const {
    double tNear = INFINITY;
    for (auto& obj : objects) {
        double t = INFINITY;
        if (obj->intersect(ray, t) && t < tNear) {
            tNear = t;
            object = obj;
        }
    }
    return (object != nullptr);
}


Vector Scene::getLighting(const Vector& point, const Vector& normal, const Light& light) const {
    Vector lightDir = (light.position - point).normalize();
    double lightIntensity = normal.dot(lightDir);
    if (lightIntensity < 0) lightIntensity = 0;

    // Print the normal, light direction, and light intensity
    std::cout << "Normal: " << normal << ", Light Direction: " << lightDir << ", Light Intensity: " << lightIntensity << std::endl;

    return Vector(1, 1, 1) * lightIntensity;  // white light
}