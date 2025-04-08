# Ray Tracer

A modern ray tracing implementation in C++ with web interface support using React and JavaScript.

## Project Structure

- `src/` - C++ source files
- `include/` - C++ header files
- `web/` - React and JavaScript web interface
- `cmake/` - CMake configuration files
- `build/` - Build output directory

## Features

- Real-time ray tracing simulation
- Web-based visualization interface
- Object-oriented design
- Cross-platform support

## Building the Project

### Prerequisites

- C++17 compatible compiler
- CMake 3.10 or higher
- Node.js and npm (for web interface)

### Build Instructions

1. Create build directory:
```bash
mkdir build && cd build
```

2. Configure and build:
```bash
cmake ..
make
```

3. Build web interface:
```bash
cd web
npm install
npm run build
```

## License

MIT License 