#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../third_party/stb_image_write.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.ppm> <output.png>\n";
        return 1;
    }

    std::string input_file = argv[1];
    std::string output_file = argv[2];

    // Open the PPM file
    std::ifstream ppm_file(input_file);
    if (!ppm_file) {
        std::cerr << "Error: Could not open input file " << input_file << "\n";
        return 1;
    }

    // Read PPM header
    std::string magic;
    int width, height, max_value;
    ppm_file >> magic >> width >> height >> max_value;

    if (magic != "P3") {
        std::cerr << "Error: Not a PPM file (P3 format)\n";
        return 1;
    }

    // Create buffer for pixel data
    std::vector<unsigned char> pixels(width * height * 3);

    // Read pixel data
    for (int i = 0; i < width * height; ++i) {
        int r, g, b;
        ppm_file >> r >> g >> b;
        pixels[i * 3] = static_cast<unsigned char>(r);
        pixels[i * 3 + 1] = static_cast<unsigned char>(g);
        pixels[i * 3 + 2] = static_cast<unsigned char>(b);
    }

    // Write PNG file
    if (!stbi_write_png(output_file.c_str(), width, height, 3, pixels.data(), width * 3)) {
        std::cerr << "Error: Could not write PNG file\n";
        return 1;
    }

    std::cout << "Successfully converted " << input_file << " to " << output_file << "\n";
    return 0;
} 