#!/bin/bash

echo "Updating System packages:"
sudo apt update

echo "Installing: libopencv-dev, cmake, build-essential"
sudo apt install -y libopencv-dev cmake build-essential

echo "--- Current package versions---"
cmake --version
gcc --version
pkg-config --modversion opencv4

if [ -f "build.sh" ]; then
    chmod +x build.sh
    chmod +x run.sh
    echo "Execute permissions succesfuly given to build.sh and run.sh"
else
    echo "Warning: build.sh is not found in current dir!"
fi

echo "--- Requirements intalled! ---"
echo "Now you can build and start this project by running: ./build.sh"
