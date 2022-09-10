cmake_minimum_required(VERSION 3.12.0)
project(strings VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(strings main.cpp)
set_property(TARGET strings PROPERTY CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(CPack)
