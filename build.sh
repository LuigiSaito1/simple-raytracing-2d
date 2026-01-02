#!/bin/bash

# Simple build script for SimpleRaytracing2D

# Create build directory if it doesn't exist
mkdir -p build
cd build

# Configure with CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build the project
cmake --build . -j$(nproc)

echo ""
echo "Build complete! Executable is in: build/bin/SimpleRaytracing2D"
