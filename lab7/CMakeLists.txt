cmake_minimum_required(VERSION 3.10)
project(Bobrov_cam)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(Bobrov_cam 
    ${OpenCV_LIBS} 
    Threads::Threads
)

configure_file(deploy.prototxt ${CMAKE_CURRENT_BINARY_DIR}/deploy.prototxt COPYONLY)
configure_file(res10_300x300_ssd_iter_140000.caffemodel ${CMAKE_CURRENT_BINARY_DIR}/res10_300x300_ssd_iter_140000.caffemodel COPYONLY)