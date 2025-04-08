cmake_minimum_required(VERSION 3.10)
project(RayTracer VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
add_subdirectory(src)

# Include directories
include_directories(include)

# Add executable
add_executable(raytracer src/main.cpp)

# Add any additional source files here
target_sources(raytracer PRIVATE
    src/ray.cpp
    src/vector3.cpp
    src/color.cpp
    src/sphere.cpp
    src/camera.cpp
)

# Add any additional libraries here
# target_link_libraries(raytracer PRIVATE ...) 