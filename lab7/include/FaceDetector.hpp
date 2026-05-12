#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>

class FaceDetector {
public:
    FaceDetector(const std::string& proto, const std::string& model);
    ~FaceDetector();
    void updateFrame(const cv::Mat& frame);
    std::vector<cv::Rect> getDetections();

private:
    void detectionLoop();

    cv::dnn::Net net;
    std::thread worker;
    std::mutex frameMutex;
    std::mutex resultMutex;
    
    std::atomic<bool> running{true};
    std::atomic<bool> hasNewFrame{false};

    cv::Mat inputFrame;
    std::vector<cv::Rect> lastResults;
};