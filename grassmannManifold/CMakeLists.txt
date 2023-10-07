cmake_minimum_required(VERSION 3.0.0)
project(grassmann VERSION 0.1.0)

include(CTest)
enable_testing()

find_package (Eigen3 REQUIRED NO_MODULE)

add_executable(grassmann src/main.cpp)

target_link_libraries(grassmann Eigen3::Eigen)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
