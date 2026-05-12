#include "WindowManager.hpp"
#include <iostream>

WindowManager::WindowManager(const std::string& name) : windowName(name) {
    cv::namedWindow(windowName);
    cv::setMouseCallback(windowName, onMouse, nullptr);
}

void WindowManager::show(const cv::Mat& frame) {
    cv::imshow(windowName, frame);
}

void WindowManager::onMouse(int event, int x, int y, int flags, void* userdata) {
    if (event == cv::EVENT_LBUTTONDOWN) {
        std::cout << "Клік мишкою на: (" << x << ", " << y << ")" << std::endl;
    }
}