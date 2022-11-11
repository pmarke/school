cmake_minimum_required(VERSION 3.0.0)
project(checkerboard VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )
find_package(Ceres REQUIRED)
find_package (Eigen3 3.3 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS}
inc
${EIGEN3_INCLUDE_DIR} )

add_executable(checkerboard main.cpp src/PatternGenerator.cpp src/Optimizer.cpp)
target_link_libraries(checkerboard ${OpenCV_LIBS} Ceres::ceres)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
