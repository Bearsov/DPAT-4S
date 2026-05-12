#pragma once
#include <string>
#include <opencv2/opencv.hpp>

class WindowManager {
public:
    WindowManager(const std::string& name);
    void show(const cv::Mat& frame);
    static void onMouse(int event, int x, int y, int flags, void* userdata);
private:
    std::string windowName;
};