cmake_minimum_required(VERSION 3.0.0)
project(basics VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(basics main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
include(CPack)
