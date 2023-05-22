#include "Image.h"
#include <string>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <algorithm>

Image::Image(int width, int height) : width(width), height(height) {
    pixels.resize(width * height);
}

void Image::setPixel(int x, int y, const Vector& color) {
    pixels[y * width + x] = color;
}

void Image::save(const std::string& filename) const {
    std::vector<unsigned char> data(width * height * 3);
    for (int i = 0; i < width * height; i++) {
        Vector color = pixels[i];
        data[i * 3 + 0] = std::min(1.0, color.x) * 255;
        data[i * 3 + 1] = std::min(1.0, color.y) * 255;
        data[i * 3 + 2] = std::min(1.0, color.z) * 255;
    }
    stbi_write_png(filename.c_str(), width, height, 3, data.data(), width * 3);
}