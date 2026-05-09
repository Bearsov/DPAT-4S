# Real-Time OpenCV Image Processor
This C++ application captures live video from a camera and applies various image processing filters (No Filter, Grayscale, Canny Edge Detection, Gaussian Blur) in real-time. Built with a modular architecture and OpenCV. Can be controlled with keyboard commands to change filters and mouse events for coordinate tracking.

## To build and use this application:
1. Download this dir and open it: `cd /path/to/dir/lab6`
2. To install requirements run: \
`chmod +x preinstall.sh` \
`sudo ./preinstall.sh` 
3. Now you can build project by running: \
`./build.sh`
4. Done! Now you can use this application.
> You can start it again by running `./run.sh` or `./lab6\build\Bobrov_cam`

### System requirements and resources usage:
- Debian or Ubuntu based distributions (tested on Ubuntu 24.04.3 LTS) 
- 600 KB storage on disk
- ~200MB RAM
- 1 core processor