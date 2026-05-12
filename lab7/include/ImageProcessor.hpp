#pragma once
#include <opencv2/opencv.hpp>

enum class ProcessMode { ORIGINAL, GRAY, CANNY, BLUR };

class ImageProcessor {
public:
    void setMode(ProcessMode mode);
    void handleKey(int key);
    void process(cv::Mat& frame);

private:
    ProcessMode currentMode = ProcessMode::ORIGINAL;
};