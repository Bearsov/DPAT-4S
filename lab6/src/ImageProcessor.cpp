#include "ImageProcessor.hpp"

void ImageProcessor::setMode(ProcessMode mode) {
    currentMode = mode;
}

void ImageProcessor::process(cv::Mat& frame) {
    if (frame.empty()) return;

    switch (currentMode) {
        case ProcessMode::GRAY: {
            cv::Mat gray;
            cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            cv::cvtColor(gray, frame, cv::COLOR_GRAY2BGR); 
            break;
        }
        case ProcessMode::CANNY: {
            cv::Mat gray, edges;
            cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            cv::Canny(gray, edges, 70, 120);
            cv::cvtColor(edges, frame, cv::COLOR_GRAY2BGR);
            break;
        }
        case ProcessMode::BLUR: {
            cv::GaussianBlur(frame, frame, cv::Size(15, 15), 0);
            break;
        }
        default:
            break; 
    }
}