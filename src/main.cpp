#include <iostream>
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../third_party/stb_image_write.h"

void write_ppm(int width, int height, const std::vector<unsigned char>& pixels) {
    // PPM Header
    std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int index = (j * width + i) * 3;
            std::cout << static_cast<int>(pixels[index]) << ' '
                      << static_cast<int>(pixels[index + 1]) << ' '
                      << static_cast<int>(pixels[index + 2]) << '\n';
        }
    }
}

void write_png(const char* filename, int width, int height, const std::vector<unsigned char>& pixels) {
    stbi_write_png(filename, width, height, 3, pixels.data(), width * 3);
}

int main() {
    // Image dimensions
    const int image_width = 20;
    const int image_height = 20;

    // Create pixel buffer
    std::vector<unsigned char> pixels(image_width * image_height * 3);

    // Generate gradient
    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;

            int index = (j * image_width + i) * 3;
            pixels[index] = static_cast<unsigned char>(255.999 * r);
            pixels[index + 1] = static_cast<unsigned char>(255.999 * g);
            pixels[index + 2] = static_cast<unsigned char>(255.999 * b);
        }
    }

    // Write PPM to stdout
    write_ppm(image_width, image_height, pixels);

    // Write PNG to file
    write_png("image.png", image_width, image_height, pixels);

    return 0;
} 