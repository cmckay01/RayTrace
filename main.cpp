#include <string>
#include "Vector.h"
#include "Ray.h"
#include "Sphere.h"
#include "Scene.h"
#include "Camera.h"
#include "Light.h"
#include "Image.h"
#include <algorithm>

int main() {
    // Define the image dimensions
    int width = 800;
    int height = 600;

    // Create an image
    Image image(width, height);

    // Create a scene
    Scene scene;

    // Add a sphere to the scene
    Sphere* sphere = new Sphere(Vector(0, 0, -5), 1, Vector(1, 0, 0), 0.5, 0.5);
    scene.add(sphere);

    // Create a camera
    Camera camera(Vector(0, 0, 0));

    // Create a light
    Light light(Vector(0, 0, 0), Vector(1, 1, 1));

    // Render the scene
    for (int y = 0; y < height; y++) {
     for (int x = 0; x < width; x++) {
        // Generate a ray for this pixel
        Ray ray = camera.getRay((x - width / 2.0) / (width / 2.0), (y - height / 2.0) / (height / 2.0));

        // Check for an intersection with the scene
        double t;
        Object* object;
        if (scene.intersect(ray, t, object)) {
            // Calculate the intersection point and normal
            Vector point = ray.origin + ray.direction * t;
            Vector normal = sphere->getNormal(point);

            // Calculate the lighting at this point
            Vector color = scene.getLighting(point, normal, light);

            // Clamp the color values to the range [0, 1]
            color.x = std::max(0.0, std::min(1.0, color.x));
            color.y = std::max(0.0, std::min(1.0, color.y));
            color.z = std::max(0.0, std::min(1.0, color.z));

            // Write the color to the pixel
            image.setPixel(x, y, color);
        }
    }
}

    // Save the image
    image.save("output.png");

    return 0;
}
