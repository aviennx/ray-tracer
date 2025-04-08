cmake_minimum_required(VERSION 3.10)
project(RayTracer VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(third_party)

# Add executable
add_executable(raytracer src/main.cpp) 