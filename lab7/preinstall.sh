#!/bin/bash

echo "Updating System packages:"
sudo apt update

echo "Installing: libopencv-dev, cmake, build-essential wget"
sudo apt install -y libopencv-dev cmake build-essential wget

echo "--- Current package versions---"
cmake --version
gcc --version
pkg-config --modversion opencv4

PROTO_URL="https://raw.githubusercontent.com/opencv/opencv/master/samples/dnn/face_detector/deploy.prototxt"
MODEL_URL="https://raw.githubusercontent.com/opencv/opencv_3rdparty/dnn_samples_face_detector_20170830/res10_300x300_ssd_iter_140000.caffemodel"

echo "Installing ResNet-10"
wget -N $PROTO_URL
wget -N $MODEL_URL

if [ -f "build.sh" ]; then
    chmod +x build.sh
    chmod +x run.sh
else
    echo "Warning: build.sh is not found in current dir!"
fi

echo "--- Requirements intalled! ---"
echo "Now you can build and start this project by running: ./build.sh"
