cmake_minimum_required(VERSION 3.10)
project(Bobrov_cam)

set(CMAKE_CXX_STANDARD 17)

# Пошук OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} include)

# Вихідний код
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})