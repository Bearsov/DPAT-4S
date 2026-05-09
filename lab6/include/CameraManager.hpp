#pragma once
#include <opencv2/opencv.hpp>

class CameraManager {
public:
    CameraManager(int deviceID = 0);
    bool isOpened() const;
    bool getFrame(cv::Mat& frame);
private:
    cv::VideoCapture cap;
};