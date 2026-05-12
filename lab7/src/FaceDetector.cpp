#include "FaceDetector.hpp"

FaceDetector::FaceDetector(const std::string& proto, const std::string& model) {
    net = cv::dnn::readNetFromCaffe(proto, model);
    worker = std::thread(&FaceDetector::detectionLoop, this);
}

FaceDetector::~FaceDetector() {
    running = false;
    if (worker.joinable()) worker.join();
}

void FaceDetector::updateFrame(const cv::Mat& frame) {
    std::lock_guard<std::mutex> lock(frameMutex);
    frame.copyTo(inputFrame);
    hasNewFrame = true;
}

std::vector<cv::Rect> FaceDetector::getDetections() {
    std::lock_guard<std::mutex> lock(resultMutex);
    return lastResults;
}

void FaceDetector::detectionLoop() {
    while (running) {
        cv::Mat frame;
        if (hasNewFrame) {
            {
                std::lock_guard<std::mutex> lock(frameMutex);
                frame = inputFrame.clone();
                hasNewFrame = false;
            }

            if (frame.empty()) continue;
            

            cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(300, 300), 
                                                cv::Scalar(104.0, 177.0, 123.0));
            net.setInput(blob);
            cv::Mat detections = net.forward();

            std::vector<cv::Rect> faces;
            cv::Mat detectionMat(detections.size[2], detections.size[3], CV_32F, detections.ptr<float>());

            for (int i = 0; i < detectionMat.rows; i++) {
                float confidence = detectionMat.at<float>(i, 2);
                if (confidence > 0.5) {
                    int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
                    int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
                    int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
                    int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);
                    faces.push_back(cv::Rect(cv::Point(x1, y1), cv::Point(x2, y2)));
                }
            }

            {
                std::lock_guard<std::mutex> lock(resultMutex);
                lastResults = faces;
            }
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}