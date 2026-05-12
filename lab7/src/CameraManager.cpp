#include "CameraManager.hpp"

CameraManager::CameraManager(int deviceID) : cap(deviceID) {}

bool CameraManager::isOpened() const {
    return cap.isOpened();
}

bool CameraManager::getFrame(cv::Mat& frame) {
    return cap.read(frame);
}