#!/bin/bash

# Run script for SimpleRaytracing2D

EXECUTABLE="build/bin/SimpleRaytracing2D"

# Check if executable exists
if [ ! -f "$EXECUTABLE" ]; then
    echo "Executable not found at $EXECUTABLE"
    echo "Please build the project first using ./build.sh"
    exit 1
fi

# Run the executable
echo "Running SimpleRaytracing2D..."
echo "----------------------------"
./$EXECUTABLE "$@"
