#include <iostream>

int main() {
    // Image dimensions
    const int image_width = 20;
    const int image_height = 20;

    // PPM Header
    // P3 means colors are in ASCII
    // Then comes width and height
    // Then comes the maximum color value (255)
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
} 