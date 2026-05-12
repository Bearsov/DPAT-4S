#include <iostream>
#include "CameraManager.hpp"
#include "ImageProcessor.hpp"
#include "WindowManager.hpp"
#include "FaceDetector.hpp"

int main() {
    CameraManager camera(0);
    if (!camera.isOpened()) {
        std::cerr << "Error: Camera is not available!" << std::endl;
        return -1;
    }

    ImageProcessor processor;
    WindowManager window("Bobrov cam");
    cv::Mat frame;

    std::cout << "Controls: 1 - Original, 2 - Gray, 3 - Canny, 4 - Blur, ESC - Exit" << std::endl;

    FaceDetector faceNet("deploy.prototxt", "res10_300x300_ssd_iter_140000.caffemodel");

    while (true) {
        if (camera.getFrame(frame)) {
            int key = cv::waitKey(1); 

            if (key == 27) break; 

            if (key != -1) { 
                processor.handleKey(key);
            }

            faceNet.updateFrame(frame);

            processor.process(frame);

            auto faces = faceNet.getDetections();
            for (const auto& rect : faces) {
                cv::rectangle(frame, rect, cv::Scalar(0, 255, 0), 2);
            }

            window.show(frame);
        }
    }

    return 0;
}