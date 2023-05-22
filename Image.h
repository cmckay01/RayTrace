#ifndef IMAGE_H
#define IMAGE_H

#include "Vector.h"
#include <vector>

class Image {
public:
    int width, height;
    std::vector<Vector> pixels;

    Image(int width, int height);
    void setPixel(int x, int y, const Vector& color);
    void save(const std::string& filename) const;
};

#endif