#include <iostream>
#include "CameraManager.hpp"
#include "ImageProcessor.hpp"
#include "WindowManager.hpp"

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

    while (true) {
        if (!camera.getFrame(frame)) break;

        processor.process(frame);
        window.show(frame);

        int key = cv::waitKey(30);
        if (key == 27) break; // ESC

        switch (key) {
            case '1': processor.setMode(ProcessMode::ORIGINAL); break;
            case '2': processor.setMode(ProcessMode::GRAY); break;
            case '3': processor.setMode(ProcessMode::CANNY); break;
            case '4': processor.setMode(ProcessMode::BLUR); break;
        }
    }

    return 0;
}