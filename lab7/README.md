# Real-Time OpenCV Image Processor with Face detection
This C++ application captures live video from a camera and applies various image processing filters (No Filter, Grayscale, Canny Edge Detection, Gaussian Blur) and face detection (via ResNet-10) in real-time. Built with a modular architecture and OpenCV. Can be controlled with keyboard commands to change filters and mouse events for coordinate tracking.

## To build and use this application:
1. Download this dir and open it: `cd /path/to/dir/lab7`
2. To install requirements run: \
`chmod +x preinstall.sh` \
`./preinstall.sh` 
3. Now you can build project by running: \
`./build.sh`
4. Done! Now you can use this application.
> You can start it again by running `./run.sh` or `./lab7/build/Bobrov_cam`


### To decrease processor usage
- Open the "src/FaceDetector.cpp" file in any text redactor
- To the row 35 add this code and set delay for which you want `std::this_thread::sleep_for(std::chrono::milliseconds(100));`
- Build this app again `./build.sh`
- And now Face detection is working with delay you set and using much less CPU
### System requirements:
- Debian or Ubuntu based distributions (tested on Ubuntu 24.04.3 LTS) 
- 25 MB free storage on disk
- 2GB RAM
- 2 core processor
